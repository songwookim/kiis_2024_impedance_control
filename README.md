# kiis_2024_impedance_control
- ubuntu 22.04
- ros2 humble

### 0. Requirements
```
pip install mujoco # 3.2.5

```

### 1. Get sensor data
```
ros2 run dclaw sensor_real
```

### 2. Send joint state and receive torque
```
ros2 run dclaw dclaw_real
```

### 3. Receive joint state from real robot and return torque
```
ros2 run dclaw dclaw_sim
```


### miscellaneous
```
colcon build --packages-select dclaw --symlink-install

ros2 pkg list
ros2 node list
ros2 pkg executables

ros2 topic list
ros2 topic hz /topic_name 
```