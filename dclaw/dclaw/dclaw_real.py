import os
import rclpy
import threading

from dynamixel_sdk import *
from custom_interfaces.srv import GetPositions, SetPositions
from custom_interfaces.msg import GetSensordata #, GetRobotCommand
from rclpy.node import Node
import hydra
from omegaconf import DictConfig
import sys
import tty
import termios
from dclaw.dynamixel_control import DynamixelControl
import numpy as np
# import torch 

class MinimalService(Node) :
    def __init__(self, cfg):
        super().__init__('dclaw_read_py_node')
        self.cfg = cfg
        self.cur_deg = None
        self.sensordata = np.zeros(18)
        self.controller = DynamixelControl(self.cfg.dynamixel)
        self.controller.connect()
        print("connected")

        self.timestep = 0.0001

        # 1) sensor connection !
        self.subscription = self.create_subscription(
            GetSensordata, 'topic_sensordata', self.listener_callback, 10
        )        
        self.client = self.create_client(SetPositions, "set_positions")
        self.get_logger().info("Subscribed to topic_sensordata.")

        # 2) simulation feedback !
        self.create_timer(self.timestep, self.send_service_callback)

        


    def send_service_callback(self):
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
            pass
        self.req = SetPositions.Request()
        self.req.ids = self.cfg.dynamixel.ids   

        cur_deg = self.controller.get_joint_positions("rad") # need to change bulk_read        
        cur_deg_rad = self.controller.dynamixel_pos_to_rad(cur_deg)
        self.req.positions = cur_deg_rad.tolist()
        self.req.sensordata = self.sensordata.flatten().tolist()
        
        self.future = self.client.call_async(self.req)
        self.future.add_done_callback(self.handle_service_callback)  
        # rclpy.spin_until_future_complete(self, self.future)

        return self.future.result()
    
    def handle_service_callback(self, future):
        response = future.result()
        # print(f"current position :\n\n {response.torques} \n\n")
        # torques = np.multiply(response.torques,10) # for papercup
        torques = np.multiply(response.torques,2.5) # for papercup
        
        if response.timestamp > 5000 :
            # self.controller.test_torqueinput(response.torques, 0)
            # print(f"\n\n res : {response.torques}")
            print(f"\nres : {(np.int64(torques).tolist())}\n\n")
            
            self.controller.test_torqueinput((np.int64(torques)))
            
            # self.controller.test_torqueinput(np.int64(np.zeros(9)))
            
        # self.cur_deg = cur_deg
        
    def listener_callback(self, msg = GetSensordata): # Sensor
        """토픽 콜백"""
        # self.controller.enable_torque()
        print("sensor !! \n")
        self.sensordata = np.array(list(msg.sensordata))
        # print(f"version : 11 {self.sensordata }\n")
        # self.controller.test_torqueinput([31,21,11], 0)
        # self.controller.test_torqueinput([21], 12)
        # self.controller.test_torqueinput([31], 11)
        # self.controller.test_torqueinput([11], 11)
        # print(f"sensordata : {sensordata}")
        
        # for i in [0,1,2] :
        #     print(f"Sensor1 {self.sensordata[0:7]} \n")
        #     print(f"Sensor2 {self.sensordata[6:12]} \n")
        #     print(f"Sensor3 {self.sensordata[11:17]} \n")
            
        
def dclaw_read_py_node(cfg):
    rclpy.init(args=None)
    minimal_service = MinimalService(cfg)
    try :
        rclpy.spin(minimal_service)
    except KeyboardInterrupt:
        minimal_service.destroy_node()
        rclpy.shutdown()

    # t1 = threading.Thread(target=minimal_service.ros)
    # t2 = threading.Thread(target=minimal_service.listener_callback)
    # t3 = threading.Thread(target=minimal_service.move_topic_listener)
    # t1.start()
    # t2.start()
    # t3.start()

@hydra.main(version_base=None, config_path= os.path.dirname(os.path.abspath(__name__))+"/src/dclaw/resource/robot_parameter", config_name="config")
def main(cfg: DictConfig):

    dclaw_read_py_node(cfg)
   

if __name__ == "__main__":
    main()
