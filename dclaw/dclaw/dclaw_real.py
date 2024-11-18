import os
import rclpy
import threading

from dynamixel_sdk import *
from custom_interfaces.srv import GetPositions, SetPositions
# from custom_interfaces.msg import SetPosition
from rclpy.node import Node
import hydra
from omegaconf import DictConfig
import sys
import tty
import termios
from dclaw.dynamixel_control import DynamixelControl

positions_deg = [0, 0, 0, 0, 0, 0, 0, 0, 0] # 10 11 12 20 21 22 30 31 32
class MinimalService(Node) :
    global packetHandler, portHandler, DXL_IDs
    def __init__(self):
        super().__init__('dclaw_read_py_node')

        # self.srv = self.create_service(GetPosition, 'get_position', self.get_present_pos)
        self.client = self.create_client(SetPositions, "set_positions")

        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        print('server is ok')
        self.req = SetPositions.Request()

    def send_request(self, idx, cur_joint_pos_rad):
        print(cur_joint_pos_rad)
        # for idx, id in enumerate(DXL_IDs) :
        print(self.req)
        self.req.ids = idx
        self.req.positions = cur_joint_pos_rad.tolist()
        self.future = self.client.call_async(self.req)
            
        rclpy.spin_until_future_complete(self, self.future)

        return self.future.result()
    
def ros(cfg):
    minimal_service = MinimalService()
    controller = DynamixelControl(cfg.dynamixel)
    controller.connect()
    
    
    while True :
        time.sleep(0.1)
        cur_joint_pos_rad = controller.get_joint_positions("rad")
        response = minimal_service.send_request(cfg.dynamixel.ids, cur_joint_pos_rad)
            
        # minimal_service.destroy_node()
    rclpy.shutdown()

def set_curr_position(cfg):
    global positions_deg, packetHandler, portHandler, DXL_IDs
    # controller = DynamixelControl(cfg.dynamixel)
    # controller.connect()
    # cur_deg = controller.get_joint_positions("rad")
    # cur_vel_deg = controller.get_joint_velocities()
    # print(f"current position : {cur_deg} \n")
    # while True :
    #         T = 100

    #     for idx, id in enumerate(DXL_IDs) :
    #         dxl_comm_result, dxl_error = packetHandler.write1ByteTxRx(portHandler, id, ADDR_TORQUE_ENABLE, TORQUE_DISABLE)
    #         dxl_present_position, dxl_comm_result, dxl_error = packetHandler.read4ByteTxRx(portHandler, id, ADDR_PRESENT_POSITION)

    #         if id in [10,20,30] :
                
    #             # 0 -> 1000
    #             # print(f'actuator id : {id}')
    #             # print(f'dxl_present_position : {id}, {dxl_present_position}')
                
    #             theta = (float(SIM_SCALE/MOTOR_SCALE)*dxl_present_position)-float(SIM_SCALE/MOTOR_SCALE)*1000.0
    #             print(f'theta : {id}, {theta}')
    #             positions_deg[idx] = theta
    #         else : #  11, 21, 31
    #             # print(f'dxl_present_position : {id}, {dxl_present_position}')
    #             theta = (float(SIM_SCALE/MOTOR_SCALE)*dxl_present_position)-float(SIM_SCALE/MOTOR_SCALE)*2000.0
    #             print(f'theta : {id}, {theta}')
    #             positions_deg[idx] = theta
    #     # print(f'all{positions_deg}')
        
def dclaw_read_py_node(cfg):
    rclpy.init(args=None)
    t1 = threading.Thread(target=ros, args=(cfg,))
    t2 = threading.Thread(target=set_curr_position, args=(cfg,))
    t1.start()
    t2.start()

@hydra.main(version_base=None, config_path= os.path.dirname(os.path.abspath(__name__))+"/src/dclaw/resource/robot_parameter", config_name="config")
def main(cfg: DictConfig):

    dclaw_read_py_node(cfg)
   

if __name__ == "__main__":
    main()
