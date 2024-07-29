#ifndef _CONTROL_CHASSIS_H_
#define _CONTROL_CHASSIS_H_

#include "qbytearray.h"
#include "VCOMCOMM.h"
#include "memory"
#include <memory>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/TwistStamped.h>


typedef struct{
    double Expect_Speed_X;
    double Expect_Speed_Y;
    double Expect_Speed_Yaw;
} Robot_Chassis_Exp_;

#endif