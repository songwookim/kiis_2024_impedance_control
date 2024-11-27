import os
import rclpy
import threading
# import mujoco_py
import mujoco as mj
import mujoco.viewer 
import math
import os
import time
from dynamixel_sdk import *
from custom_interfaces.srv import GetPositions, SetPositions
# from custom_interfaces.msg import SetPositions
import rclpy.logging
from rclpy.node import Node
import numpy as np
import matplotlib.pyplot as plt

class MinimalService(Node) :
    global packetHandler, portHandler, DXL_IDs, positions_deg
   
    def __init__(self):
        rclpy.init(args=None)
        super().__init__('dclaw_sim_py_node')
        
        rclpy.logging.get_logger('dclaw_sim_py_node').info('\n\n HIHI \n\n')
        # self.get_logger() or  Node.get_logger(self).info('\n\nhello world 3 !!\n\n')

        self.srv = self.create_service(SetPositions, 'set_positions', self.get_present_pos)
        # self.msg = self.create_service(GetSensordata, 'get_sensordata', self.get_present_sensordata)
        pkg_path = os.path.dirname(os.path.abspath(__name__)) # ~/<pkg_path>
        xml_path = pkg_path+'/src/dclaw/resource/robel_sim/dclaw/dclaw3xh.xml'
        self.model = mj.MjModel.from_xml_path(xml_path)    
        self.data = mj.MjData(self.model)
        self.positions_deg = [.0, .0, .0, .0, .0, .0, .0, .0, .0] # 10 11 12 20 21 22 30 31 32
        self.torques = np.array([.0, .0, .0, .0, .0, .0, .0, .0, .0],dtype=float) # 10 11 12 20 21 22 30 31 32
        self.timestamp = 0
    # def get_present_sensordata(self, req, res):
    #     global positions_deg
        
    #     res.positions = positions_deg
    #     return res
    
    def get_present_pos(self, req, res):
        
        
        ids = req.ids
        pos_deg = req.positions
        for idx, id in enumerate(ids) :
            if id in [11,12,21,22,31,32] :
                self.positions_deg[idx] = pos_deg[idx] - 3.14
            else :
                self.positions_deg[idx] = pos_deg[idx] - 1.57
        # time.sleep(0.01)
        print(f"\nget : {self.positions_deg}\n")
        print(self.torques)
        res.torques = self.torques.tolist()
        res.timestamp = self.timestamp
        return res
    def get_torque(self):

        return
    def simulate(self):
        desired_stiffness = 0
        desired_damping = 0
        desired_inertia = 0     # compare 1 with 30
        goal = [-0., -0.0, 0.1] #Desire position
        force_list = []
        f_imp_list = []
        with mujoco.viewer.launch_passive(self.model, self.data) as viewer:
            viewer.sync()
            viewer.user_scn.ngeom += 1
            # initial setting : geom, type, size, pos, rot, rgba
            mujoco.mjv_initGeom(viewer.user_scn.geoms[viewer.user_scn.ngeom - 1], 
                    mujoco.mjtGeom.mjGEOM_CAPSULE, 
                    np.zeros(3), np.zeros(3), np.zeros(9), np.array([1, 0., 0., 1]))

            # change setting : change value of geom
            mujoco.mjv_connector(viewer.user_scn.geoms[viewer.user_scn.ngeom - 1], 
                    mujoco.mjtGeom.mjGEOM_CAPSULE, 0.01,
                    np.array(goal)-0.001,
                    np.array(goal))

            time = 0
            Tip_pos1 = np.array([self.data.site("FFtip").xpos, self.data.site("MFtip").xpos, self.data.site("THtip").xpos])
            Tip_pos2 = np.zeros([3,3])
            Tip_vel1 = np.zeros([3,3])
            Tip_vel2 = np.zeros([3,3])
            Tip_acc = np.zeros([3,3])
            jacp = np.zeros((3,3, self.model.nv)) #translation jacobian (NUMBER OF JOINT x NUM_OF_ACTUATORS)
            jacr = np.zeros((3,3, self.model.nv)) #rotational jacobian
            tips = ["FFtip", "MFtip", "THtip"]

            end_effector_id = []
            end_effector_id.append(self.model.body('FFL12').id)
            end_effector_id.append(self.model.body('MFL22').id)
            end_effector_id.append(self.model.body('THL32').id)
            dt = 0.0025

            while viewer.is_running():
                F_imp = np.zeros([1,9])
                time += 1
                data = self.data
                model = self.model
                for idx, tip in enumerate(tips):
                    x_error = np.subtract(goal, data.site(tip).xpos)
                    
                    mujoco.mj_jac(model, data, jacp[idx, :], jacr[idx, :], data.site(tip).xpos, end_effector_id[idx])
                    xvel = jacp[idx, :]@data.qvel 
                # -------------------------------------------
                    Tip_pos2[idx, :] = data.site(tip).xpos.copy()
                    Tip_vel2[idx, :] = (Tip_pos2[idx, :] - Tip_pos1[idx, :]) / dt
                    Tip_acc[idx, :] = (Tip_vel2[idx, :] - Tip_vel1[idx, :]) / dt

                    Tip_vel1[idx, :] = Tip_vel2[idx, :].copy()  
                    Tip_pos1[idx, :] = Tip_pos2[idx, :].copy()
                # -------------------------------------------

                    xacc = Tip_acc[idx, :]       # data.body('FFL12').cacc[3:6]
                
                    F_imp += jacp[idx].T @ (desired_inertia*xacc + desired_damping*xvel + desired_stiffness*x_error) 

                M = np.zeros((model.nv, model.nv)) # 9x9
                mj.mj_fullM(model, M, data.qM)

                c = data.qfrc_bias # bais force (centrifugal, coriolis, gravity)

                # by computation stabliity (https://github.com/google-deepmind/mujoco/issues/168)
                # 1. change solver : implicitfast -> RK4
                # 2. add actuactor friction
                data.qacc = data.qacc / 10 
                
                self.torques = (F_imp + M@data.qacc + c)[0]
                self.timestamp = time
                # print(f"\ntorques : {self.torques}\n")
                
                
                # change joint positions
                for idx, position_deg in enumerate(self.positions_deg) :
                    self.data.ctrl[idx] = position_deg
                # with viewer.lock():
                #     viewer.opt.flags[mujoco.mjtVisFlag.mjVIS_CONTACTFORCE] = 1

                force_list.append(data.sensor("ft_sensor_force").data.copy())
                f_imp_list.append(F_imp[0])
                #Step the simulation.
                mj.mj_forward(model, data)
                mj.mj_step(model, data)
                viewer.sync()
        _, ax = plt.subplots(2, 1, sharex=True, figsize=(10, 10))
        force_list = np.array(force_list)
        f_imp_list = np.array(f_imp_list)
        sim_time = range(time)
        lines = ax[0].plot(sim_time,force_list, label='Force sensor')
        ax[0].set_title('Force sensor')
        ax[0].set_ylabel('Newtons')
        ax[0].set_xlabel('time')
        ax[0].legend(iter(lines), ('$F_x$', '$F_y$', '$F_z$'))

        lines = ax[1].plot(sim_time,f_imp_list, label='Impedance controller')
        ax[1].set_title('Impedance controller')
        ax[1].set_ylabel('Newtons')
        ax[1].set_xlabel('time')
        ax[1].legend(iter(lines), ('FFL10','FFL11','FFL12','MFL20','MFL21','MFL22','THL30','THL31','THL32'))
        plt.tight_layout()
        plt.show()




# def ros():
    
#     pass


def read_write_py_node():

    try :
        minimal_service = MinimalService()
        
        # rclpy.spin(minimal_service)
        t1 = threading.Thread(target=rclpy.spin, args=(minimal_service,))
        t2 = threading.Thread(target=minimal_service.simulate)
        t1.start()
        t2.start()
    except KeyboardInterrupt:
        print("KeyboardInterrupt")
        rclpy.shutdown()
        t1.join()
        t2.join()


def main():
    read_write_py_node()


if __name__ == '__main__':
    main()