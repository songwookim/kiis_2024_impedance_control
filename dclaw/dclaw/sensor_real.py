import socket
import time
import sys
import array
import os
import hydra
from omegaconf import DictConfig
import numpy as np
from dclaw.sensor_MMS101 import MMS101Controller
import rclpy
from rclpy.node import Node

from std_msgs.msg import String
from custom_interfaces.msg import GetSensordata

class MinimalPublisher(Node):

    def __init__(self, cfg):
        super().__init__('sensor_node')
        self.cfg = cfg

        self.publisher_ = self.create_publisher(GetSensordata, 'topic_sensordata', 10)
        # timer_period = 0.5  # seconds
        while rclpy.ok():
            self.sensor_callback(cfg)
            
        self.i = 0

    def sensor_callback(self, cfg):
        msg = GetSensordata()
        mms101 = MMS101Controller(self.cfg)
        sensordata = mms101.run()
        msg.sensordata = sensordata.flatten().tolist()
        self.get_logger().info(f"{sensordata}\n\n")
        # msg.sensordata = sensordata
        
        self.publisher_.publish(msg)

@hydra.main(version_base=None, config_path= os.path.dirname(os.path.abspath(__name__))+"/src/dclaw/resource/sensor_parameter", config_name="config")
def main(config):
    try:
        rclpy.init()
        minimal_publisher = MinimalPublisher(config)
        rclpy.spin(minimal_publisher)
    except KeyboardInterrupt:
        print("KeyboardInterrupt")    
        minimal_publisher.destroy_node()
        rclpy.shutdown() # 4


if main == "__main__":
    mms101 = MMS101Controller()
    mms101.run()