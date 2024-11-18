import os
import rclpy
import threading
# import mujoco_py
import mujoco as mj
import mujoco.viewer 
import math
import os
from dynamixel_sdk import *
from custom_interfaces.srv import GetPositions, SetPositions
# from custom_interfaces.msg import SetPositions
import rclpy.logging
from rclpy.node import Node
import numpy as np

# 10[0],20[3],30[6] : 0-> 1000, 11,12,21,22,31,320 -> 2000
positions_deg = [.0, .0, .0, .0, .0, .0, .0, .0, .0] # 10 11 12 20 21 22 30 31 32
SIM_SCALE = 4
MOTOR_SCALE = 4096

class MinimalService(Node) :
    global packetHandler, portHandler, DXL_IDs, positions_deg
    def __init__(self):
        super().__init__('dclaw_sim_py_node')
        rclpy.logging.get_logger('dclaw_sim_py_node').info('\n\n HIHI \n\n')
        # self.get_logger() or  Node.get_logger(self).info('\n\nhello world 3 !!\n\n')

        self.srv = self.create_service(SetPositions, 'set_positions', self.get_present_pos)

    def get_present_pos(self, req, res):
        global positions_deg
        
        ids = req.ids
        pos_deg = req.positions
        for idx, id in enumerate(ids) :
            if id in [11,12,21,22,31,32] :
                positions_deg[idx] = pos_deg[idx] - 3.14
            # elif id == 10 :
                # positions_deg[idx] = pos_deg[idx] - 0.03
            else :
                positions_deg[idx] = pos_deg[idx] - 1.57
            # positions_deg[idx] = positions_deg[idx] 
        print(positions_deg)
        res.positions = pos_deg
        return res
            
def ros():
    minimal_service = MinimalService()
    rclpy.spin(minimal_service)

def simulate():
    global positions_deg
    # mj_path = mujoco_py.utils.discover_mujoco()
    pkg_path = os.  path.dirname(os.path.abspath(__name__)) # ~/<pkg_path>
    xml_path = pkg_path+'/src/dclaw/resource/robel_sim/dclaw/dclaw3xh.xml'
    # xml_path = os.path.join( xml_path)
    # '/home/songwoo/.mujoco/mujoco210/model/robel_sim/dclaw/dclaw3xh.xml'   => install mujoco210
    model = mj.MjModel.from_xml_path(xml_path)    
    data = mj.MjData(model)

    t=0
    with mujoco.viewer.launch_passive(model, data) as viewer:
        while viewer.is_running():
            viewer.sync()
            mj.mj_step(model, data)

            # os.system('clear')
            for idx, position_deg in enumerate(positions_deg) :
                # print(f'{idx}, {position_deg}')
                data.ctrl[idx] = position_deg
                # data.ctrl[1] = 90   # actuator ID 11
                # data.ctrl[2] = 90   # actuator ID 12
                # data.ctrl[3] = 180 # actuator ID 20  (actuactor degree which is abs(45) bounded by .mjcf)
                # data.ctrl[4] = math.cos(t / 10.) * 0.1 # actuator ID 21
                # data.ctrl[5] = math.sin(t / 10.) * 0.1 # actuator ID 22
                # data.ctrl[6] = math.cos(t / 10.) * 0.1 # actuator ID 30
                # data.ctrl[7] = math.sin(t / 10.) * 0.1 # actuator ID 31
                # data.ctrl[8] = math.sin(t / 10.) * 0.1
                #  # actuator ID 32
            
        # t += 1
        # sim.step(t)
        # viewer.render()
        # if t > 100 and os.getenv('TESTING') is not None:
        #     break

def read_write_py_node():
    
    rclpy.init(args=None)
    t1 = threading.Thread(target=ros)
    t2 = threading.Thread(target=simulate)
    t1.start()
    t2.start()



def main():
    
    read_write_py_node()


if __name__ == '__main__':
    main()