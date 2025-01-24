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
        self.mms101 = MMS101Controller(self.cfg)
        self.timer_period = 0.0001
        self.publisher_ = self.create_publisher(GetSensordata, 'topic_sensordata', 10)
        # self.create_callback_group(rclpy.callback_groups.ReentrantCallbackGroup())

        self.timer = self.create_timer(self.timer_period, self.sensor_callback)
        # timer_period = 0.5  # seconds
        self.i = 0


    def sensor_callback(self):          
        msg = GetSensordata()
        # mms101 = MMS101Controller(self.cfg) # warning !!
        sensordata = self.mms101.run(self.i)
        msg.sensordata = sensordata.flatten().tolist()
        
        # self.get_logger().info(f"{sensordata}\n\n")
        self.i += 1
        
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


if __name__ == "__main__":
    main()