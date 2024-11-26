import sys
import tty
import termios
from dynamixel_sdk import *  # Uses Dynamixel SDK library
import numpy as np  
class DynamixelControl:
    def __init__(self, config):
        self.cfg = config
        self.portHandler = PortHandler(self.cfg.device_name)
        self.packetHandler = PacketHandler(self.cfg.protocol_version)
        self.old_settings = termios.tcgetattr(sys.stdin.fileno())

    def getch(self):
        fd = sys.stdin.fileno()
        try:
            tty.setraw(fd)
            ch = sys.stdin.read(1)
        finally:
            termios.tcsetattr(fd, termios.TCSADRAIN, self.old_settings)
        return ch

    def connect(self):
        
        if self.portHandler.openPort():
            print("Succeeded to open the port")
        else:
            raise Exception("Failed to open the port")

        if self.portHandler.setBaudRate(self.cfg.baudrate):
            print("Succeeded to change the baudrate")
        else:
            raise Exception("Failed to change the baudrate")
        self.disable_torque()
        for id in self.cfg.ids:
            cur_Operating_mode = self.get_operating_mode(id)
            if cur_Operating_mode != self.cfg.control_modes.default_mode:
                self.set_operating_mode_one(id, self.cfg.control_modes.default_mode)
        
        self.enable_torque() # for dynamaixel operation
        # self.disable_torque() # for torque input operation


    def set_operating_mode_all(self, mode):
        for id in self.cfg.ids:
            # mode = self.cfg.control_modes.default_mode
            addr_operating_mode = self.cfg.control_table.addr_operating_mode
            dxl_comm_result, dxl_error = self.packetHandler.write1ByteTxRx(
                self.portHandler, id, addr_operating_mode, mode)
            if dxl_comm_result != COMM_SUCCESS:
                raise Exception(f"Failed to set operating mode: {self.packetHandler.getTxRxResult(dxl_comm_result)}")
            elif dxl_error != 0:
                raise Exception(f"Dynamixel error: {self.packetHandler.getRxPacketError(dxl_error)}")
            else:
                print(f"Dynamixel ID {id} set to mode {mode}")
    def set_operating_mode_one(self, id, mode ):
        # mode = self.cfg.control_modes.default_mode
        addr_operating_mode = self.cfg.control_table.addr_operating_mode
        dxl_comm_result, dxl_error = self.packetHandler.write1ByteTxRx(
            self.portHandler, id, addr_operating_mode, mode)
        if dxl_comm_result != COMM_SUCCESS:
            raise Exception(f"Failed to set operating mode: {self.packetHandler.getTxRxResult(dxl_comm_result)}")
        elif dxl_error != 0:
            raise Exception(f"Dynamixel error: {self.packetHandler.getRxPacketError(dxl_error)}")
        else:
            print(f"Dynamixel ID {id} set to mode {mode}")

    def get_operating_mode_all(self) -> int:
        addr_operating_mode = self.cfg.control_table.addr_operating_mode
        for id in self.cfg.ids:
            dxl_current_state, dxl_comm_result, dxl_error = self.packetHandler.read1ByteTxRx( # state -> mode depenedent
                self.portHandler, id, addr_operating_mode)
            if dxl_comm_result != COMM_SUCCESS:
                raise Exception(f"Failed to get operating mode: {self.packetHandler.getTxRxResult(dxl_comm_result)}")
            elif dxl_error != 0:
                raise Exception(f"Dynamixel error: {self.packetHandler.getRxPacketError(dxl_error)}")
            else:
                print(f"Operating mode for Dynamixel ID {id} is {dxl_current_state}")
        return dxl_current_state
    
    def get_operating_mode(self, id) -> int:
        addr_operating_mode = self.cfg.control_table.addr_operating_mode
        dxl_current_state, dxl_comm_result, dxl_error = self.packetHandler.read1ByteTxRx( # state -> mode depenedent
            self.portHandler, id, addr_operating_mode)
        if dxl_comm_result != COMM_SUCCESS:
            raise Exception(f"Failed to get operating mode: {self.packetHandler.getTxRxResult(dxl_comm_result)}")
        elif dxl_error != 0:
            raise Exception(f"Dynamixel error: {self.packetHandler.getRxPacketError(dxl_error)}")
        else:
            print(f"Operating mode for Dynamixel ID {id} is {dxl_current_state}")
        return dxl_current_state
    
    def enable_torque(self):
        addr_torque_enable = self.cfg.control_table.addr_torque_enable
        for id in self.cfg.ids:
            dxl_comm_result, dxl_error = self.packetHandler.write1ByteTxRx(
                self.portHandler, id, addr_torque_enable, self.cfg.torque_enable)
            if dxl_comm_result != COMM_SUCCESS:
                raise Exception(f"Failed to enable torque: {self.packetHandler.getTxRxResult(dxl_comm_result)}")
            elif dxl_error != 0:
                raise Exception(f"Dynamixel error: {self.packetHandler.getRxPacketError(dxl_error)}")
            else:
                print(f"Torque enabled for Dynamixel ID {id}")

    def dynamixel_pos_to_deg(self, pos):
        return np.array(pos) * 0.0879120879
    
    def dynamixel_pos_to_rad(self, pos) -> np.array:
        return np.array(pos) * 0.001533981

    
    def get_joint_velocities(self) :
        ADDR_PRESENT_VELOCITY = self.cfg.control_table.ADDR_PRESENT_VELOCITY
        dxl_present_velocities = []
        for id in self.cfg.ids:
            dxl_present_velocity, dxl_comm_result, dxl_error = self.packetHandler.read4ByteTxRx(
                self.portHandler, id, ADDR_PRESENT_VELOCITY)
            if dxl_comm_result != COMM_SUCCESS:
                raise Exception(f"Failed to get velocity: {self.packetHandler.getTxRxResult(dxl_comm_result)}")
            elif dxl_error != 0:
                raise Exception(f"Dynamixel error: {self.packetHandler.getRxPacketError(dxl_error)}")
            # else:
            #     print(f"Velocity for Dynamixel ID {id} is {dxl_present_velocity}")
            if dxl_present_velocity > 0x7fffffff:
                dxl_present_velocity = dxl_present_velocity - 4294967296
            dxl_present_velocities.append(dxl_present_velocity)
        
        return np.array(dxl_present_velocities)
    
    def get_joint_positions(self, type) -> list[int]:
        ADDR_PRESENT_POSITION = self.cfg.control_table.ADDR_PRESENT_POSITION
        dxl_present_positions = []

        for id in self.cfg.ids:
            dxl_present_position, dxl_comm_result, dxl_error = self.packetHandler.read4ByteTxRx(
                self.portHandler, id, ADDR_PRESENT_POSITION)
            if dxl_comm_result != COMM_SUCCESS:
                raise Exception(f"Failed to get position: {self.packetHandler.getTxRxResult(dxl_comm_result)}")
            elif dxl_error != 0:
                raise Exception(f"Dynamixel error: {self.packetHandler.getRxPacketError(dxl_error)}")
            else:
                # print(f"Position for Dynamixel ID {id} is {dxl_present_position}")
                pass
            dxl_present_positions.append(dxl_present_position*0.1*10)

        return dxl_present_positions

    def set_joint_positions(self, type, ids, goal_pos) -> list[int]:
        ADDR_GOAL_POSITION = self.cfg.control_table.ADDR_GOAL_POSITION
        # dxl_present_positions = [1000,2000,2000,1000,2000,2000,1000,2000,2000]

        
        for idx,id in enumerate(ids):
            self.set_operating_mode_one(id,self.cfg.control_modes.position_control_mode)
            dxl_present_position, dxl_comm_result, dxl_error = self.packetHandler.write4ByteTxRx(
                self.portHandler, id, ADDR_GOAL_POSITION, goal_pos[idx])
            if dxl_comm_result != COMM_SUCCESS:
                raise Exception(f"Failed to get position: {self.packetHandler.getTxRxResult(dxl_comm_result)}")
            elif dxl_error != 0:
                raise Exception(f"Dynamixel error: {self.packetHandler.getRxPacketError(dxl_error)}")
            # else:
            #     print(f"Position for Dynamixel ID {id} is {dxl_present_position}")
            # dxl_present_positions.append(dxl_present_position*0.1*10)
        self.set_operating_mode_all(self.cfg.control_modes.default_mode)

        if type=="rad": # 1.57 rad = 90 deg
            return self.dynamixel_pos_to_rad(dxl_present_positions)
        elif type=="deg":
            return self.dynamixel_pos_to_deg(dxl_present_positions)
        else: # dynamixel setting value
            return np.array(dxl_present_positions)

        
    
    def disable_torque(self):
        addr_torque_enable = self.cfg.control_table.addr_torque_enable
        for id in self.cfg.ids:
            dxl_comm_result, dxl_error = self.packetHandler.write1ByteTxRx(
                self.portHandler, id, addr_torque_enable, self.cfg.torque_disable)
            if dxl_comm_result != COMM_SUCCESS:
                print(f"Failed to disable torque: {self.packetHandler.getTxRxResult(dxl_comm_result)}")
            elif dxl_error != 0:
                print(f"Dynamixel error: {self.packetHandler.getRxPacketError(dxl_error)}")
            else:
                print(f"Torque disabled for Dynamixel ID {id}")
                
    def test_torqueinput(self, ids, input_torque):
        ADDR_GOAL_CURRENT = self.cfg.control_table.ADDR_GOAL_CURRENT
        for id in ids:
            dxl_comm_result, dxl_error = self.packetHandler.write2ByteTxRx(
                self.portHandler, id, ADDR_GOAL_CURRENT, input_torque)
            if dxl_comm_result != COMM_SUCCESS:
                raise Exception(f"Failed to write torque: {self.packetHandler.getTxRxResult(dxl_comm_result)}")
            elif dxl_error != 0:
                raise Exception(f"Dynamixel error: {self.packetHandler.getRxPacketError(dxl_error)}")
            else:
                print(f"Torque written for Dynamixel ID {id}")
    
    def test_torqueinput_one(self, id, input_torque):
        ADDR_GOAL_CURRENT = self.cfg.control_table.ADDR_GOAL_CURRENT
        print(f"\n\n{id}\n\n")
        dxl_comm_result, dxl_error = self.packetHandler.write2ByteTxRx(
            self.portHandler, id, ADDR_GOAL_CURRENT, input_torque)
        if dxl_comm_result != COMM_SUCCESS:
            raise Exception(f"Failed to write torque: {self.packetHandler.getTxRxResult(dxl_comm_result)}")
        elif dxl_error != 0:
            raise Exception(f"Dynamixel error: {self.packetHandler.getRxPacketError(dxl_error)}")
        else:
            print(f"Torque written for Dynamixel ID {id}")
    def close_port(self):
        self.disable_torque()
        self.portHandler.closePort()
        print("Port closed")
