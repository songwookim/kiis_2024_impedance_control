import socket
import time
import sys
import array
import os
import hydra
from omegaconf import DictConfig
import numpy as np

# Sensor Constants
PROTOCOL_SPI = 0x01
SENSOR_MAP = {
    1: 0x01,
    2: 0x02,
    3: 0x04,
    4: 0x08,
    5: 0x10
}


class MMS101Controller:
    def __init__(self, config):
        self.dest_ip = config.mms101.dest_ip
        self.dest_port = config.mms101.dest_port
        self.src_port = config.mms101.src_port
        self.measure_max = config.mms101.measure_max
        self.debug_mode = config.mms101.debug
        self.sensors = config.mms101.sensors

        self.n_samples = 0
        self.sums = 0
        self.contact_flag = 0
        self.n_sensors = config.mms101.n_sensors

        self.destAddr = (self.dest_ip, self.dest_port)
        self.srcAddr = ("", self.src_port)
        self.sockOpenFlag = 0
        self.sensorNo = self.select_sensors(self.sensors)
        self.sockOpen()

        self.offset = [ # from value .. for three sensor
            [8.192, 2.408, -9.377, 0.02204, -0.03774, 0.00149],
            [-0.249, -0.497, -21.916, -0.03245, 0.00843, 0.00425],
            [0.536, -5.577, -34.795, -0.04001, -0.01117, -0.00093],
        ]
        # [8.36421440000005, 2.183672700000004, -10.713885600000088, 0.02242086500000042, -0.037813711999999736, -0.0010512370000000009],
        # [-0.04749409999999947, -0.7636865000000049, -22.082769699999872, -0.03188875300000068, 0.008093128999999978, 0.0027501949999999904],
        # [0.883569300000005, -6.541234199999963, -38.84847440000024, -0.039831948000000714, -0.012960584000000108, -0.002638050999999999]
        if self.n_sensors != 3:
            print("Error: Only 3 sensors are supported")
            sys.exit()

        self.cmdReset()
        self.cmdSelect()
        self.cmdBoot()

        while True:
            status = self.cmdStatus()
            if status[4] == 0x03:  # READY state
                break
            elif status[4] == 0x02:
                # time.sleep(0.001)
                # print("Waiting...")
                pass
            else:
                print("BOOT Error")
                sys.exit()
    
    def __del__(self):
        self.sockClose()

    def sockOpen(self):
        self.sockDsc = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.sockDsc.bind(self.srcAddr)
        self.sockOpenFlag = 1

    def sockClose(self):
        if self.sockOpenFlag:
            self.cmdStop()
            self.sockDsc.close()
            self.sockOpenFlag = 0

    def recvData(self, rcvLen):
        data = self.sockDsc.recv(rcvLen)
        if self.debug_mode:
            print(data.hex())
        return data

    def cmdStart(self):
        self.send_cmd([0xF0])
        return self.recvData(2)

    def cmdData(self):
        self.send_cmd([0xE0])
        return self.recvData(100)

    def cmdRestart(self):
        self.send_cmd([0xC0])
        return self.recvData(2)

    def cmdBoot(self):
        self.send_cmd([0xB0])
        return self.recvData(100)

    def cmdStop(self):
        self.send_cmd([0xB2])
        return self.recvData(2)

    def cmdReset(self):
        self.send_cmd([0xB4])
        return self.recvData(2)

    def cmdStatus(self):
        self.send_cmd([0x80])
        return self.recvData(6)

    def cmdSelect(self):
        self.send_cmd([0xA0, PROTOCOL_SPI, self.sensorNo])
        return self.recvData(2)

    def cmdVersion(self):
        self.send_cmd([0xA2])
        return self.recvData(8)

    def send_cmd(self, cmd):
        sendSz = self.sockDsc.sendto(array.array('B', cmd), self.destAddr)
        if sendSz != len(cmd):
            print(f"Error: Command send {cmd}")

    def select_sensors(self, sensor_list):
        selected = 0
        for sens in sensor_list:
            if sens in SENSOR_MAP:
                selected |= SENSOR_MAP[sens]
        return selected

    def run(self, period):
        # print("Starting Measurement...")

        self.cmdStart()
        time.sleep(0.0001)

        dataCounter = 0
        elapsTime = 0
        mms101data = np.zeros([self.n_sensors, 6])

        # while dataCounter < self.measure_max:
        rData = self.cmdData()
        # os.system('clear')
        if len(rData) == 100 and rData[0] == 0x00:
            measStatus = (rData[2] << 8) + rData[3]
            measCount = (rData[4] << 8) + rData[5]
            intervalTime = (rData[6] << 24) + (rData[7] << 16) + (rData[8] << 8) + rData[9]
            elapsTime += intervalTime / 1000000

            for sens in range(self.n_sensors):
                for axis in range(6):
                    base_index = (sens * 18) + (axis * 3) + 10
                    mms101data[sens][axis] = (rData[base_index] << 16) + (rData[base_index + 1] << 8) + rData[base_index + 2]
                    if mms101data[sens][axis] >= 0x00800000:
                        mms101data[sens][axis] -= 0x1000000

                    mms101data[sens][axis] /= 1000 if axis < 3 else 100000

            # Print debug information
            # print(f'intervalTime : {intervalTime},{measCount}')

            # Accumulate sums for offset calculation


            # Calculate dynamic offset after collecting sufficient samples
            # Apply the offset to correct the data
            sensed_data = (np.array(mms101data) - np.array(self.offset))
            if np.abs(sensed_data.sum()) > 0.1 and period > 5000 :
                self.contact_flag = 1
            else:
                self.contact_flag = 0
            print(f"{period} : {sensed_data.sum().round(2)}" )
            print(f" is? : {self.contact_flag}" )
            # if self.contact_flag != True:  
            #     # 튀는 값 필터링
            if period < 5000:
                self.sums += mms101data
                self.n_samples += 1      
                if self.n_samples > 300: 
                    self.offset = self.sums / self.n_samples  # Calculate the average offset
                    self.n_samples = 0  # Reset the number of samples
                    self.sums = 0
            else :
                if self.contact_flag == 0:
                    self.sums += mms101data
                    self.n_samples += 1  
                if self.contact_flag == 0 :
                    if self.n_samples > 300: 
                        self.offset = self.sums / self.n_samples  # Calculate the average offset
                        self.n_samples = 0  # Reset the number of samples
                        self.sums = 0


            return sensed_data        
            
            


