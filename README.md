# 分别使用2DLidar和3DLidar进行导航

## 概述

* ROS版本：noetic
* Ubuntu版本：Ubuntu20.04
* 2D里程计算法：RF2O（空旷环境下不稳定）
* 2D雷达：镭神M10P
* 3D里程计算法：FAST_LIO2
* 3D雷达：Livox-Mid-360
* SLAM建图算法：GMapping
* 导航算法：Navigation
* 重定位算法：TODO

## WorkSpace架构

```bash
├── 2DLidar					# 2D雷达驱动及里程计算法
│   ├── Lslidar_ROS1_driver		# 镭神M10P雷达驱动
│   └── rf2o_laser_odometry		# 纯2DLidar里程计
├── 3DLidar					# 3D雷达驱动及里程计算法
│   ├── FAST_LIO				# Fast-LIO激光惯导里程计
│   ├── livox_ros_driver		# Fast-LIO依赖
│   └── livox_ros_driver2		# Mid-360驱动
├── navigation				# 导航算法主体
├── slam_gmapping			# SLAM算法主体
├── system_bringup			# 启动导航系统pkg
│   ├── CMakeLists.txt
│   ├── config
│   │   └── move_base_config
│   │       ├── base_local_planner_params.yaml	# DWA参数
│   │       ├── costmap_common_params.yaml		# GlobalCostMap/LocalCostMap参数
│   │       ├── global_costmap_params.yaml		# GlobalCostMap参数
│   │       └── local_costmap_params.yaml		# LocalCostMap参数
│   ├── launch
│   │   ├── 2d_nav				# 2d导航方案启动集合
│   │   │   ├── gmapping_lidar.launch		# GMapping启动
│   │   │   ├── move_base_bringup.launch	# move_base启动
│   │   │   └── system_bringup_2d.launch	# 启动整体系统（集成上两个）
│   │   └── 3d_nav				# 3d导航方案启动集合
│   │       ├── gmapping_lidar.launch		# GMapping启动
│   │       ├── move_base_bringup.launch	# move_base启动
│   │       ├── pointcloud2laserscan.launch # 使用3DLidar获取2D点云
│   │       └── system_bringup_3d.launch	# 启动整体系统（集成上三个）
│   ├── rviz
│   │   ├── system_2d.rviz		# 2d导航方案rviz配置
│   │   └── system_3d.rviz		# 3d导航方案rviz配置
│   └── src
│       └── receive_odom.cpp	# 接收odom发布tf变换
└── user_package				# 做下位机通信
    ├── CMakeLists.txt
    ├── include
    │   └── user_package
    │       └── control_chassis.h
    ├── package.xml
    └── src
        └── control_chassis.cpp

```

