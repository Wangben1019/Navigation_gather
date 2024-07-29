#include "ros/init.h"
#include "ros/publisher.h"
#include "ros/rate.h"
#include "ros/ros.h"
#include "ros/subscriber.h"
#include "user_package/control_chassis.h"
#include <VCOMCOMM.h>
#include <cstdint>
#include "std_msgs/String.h"

#include <memory>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/TwistStamped.h>
#include <sensor_msgs/Joy.h>

#include <message_filters/subscriber.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <message_filters/synchronizer.h>

#include <boost/smart_ptr.hpp>
#include <boost/make_shared.hpp>

bool Navigation_Mode_now = true;

sensor_msgs::Joy joy_laser;

// std::shared_ptr<control_chassis_ns::control_chassis> vcom_trinsmit_speed(new control_chassis_ns::control_chassis());
void OdometryAndCmd_VelHandler(const geometry_msgs::Twist::ConstPtr& cmd_vel)
{
    Robot_Chassis_Exp_ Robot_Chassis_Exp;
    VCOMCOMM vcom_user;
    QByteArray serial_data_user;
    
    Robot_Chassis_Exp.Expect_Speed_X = cmd_vel->linear.x;
    Robot_Chassis_Exp.Expect_Speed_Y = cmd_vel->linear.y;
    Robot_Chassis_Exp.Expect_Speed_Yaw = cmd_vel->angular.z;

    // robot_expect = (Robot_Chassis_Exp_ *)serial_data_user.data();
    serial_data_user.append((char *)&Robot_Chassis_Exp, sizeof(Robot_Chassis_Exp_));
    ROS_INFO("X = %f,Y = %f,YAW = %f", Robot_Chassis_Exp.Expect_Speed_X, Robot_Chassis_Exp.Expect_Speed_Y, Robot_Chassis_Exp.Expect_Speed_Yaw);

    // ROS_INFO("Robot is in navigation mode");

    vcom_user.Transmit(1, 1, serial_data_user);
}

void joystickHandler(const sensor_msgs::Joy::ConstPtr& joy)
{
    joy_laser = *joy;
    Remote_Chassis_Exp_ Robot_Chassis_Exp;
    VCOMCOMM vcom_user;
    QByteArray serial_data_user;

    Robot_Chassis_Exp.remote_speed_x = joy_laser.axes[4];
    Robot_Chassis_Exp.remote_speed_y = joy_laser.axes[3];
    Robot_Chassis_Exp.remote_speed_yaw = joy_laser.axes[0];
    Robot_Chassis_Exp.switch_remote = joy_laser.axes[2];
    Robot_Chassis_Exp.remote_stop_flag = joy_laser.buttons[4];


    // robot_expect = (Robot_Chassis_Exp_ *)serial_data_user.data();
    serial_data_user.append((char *)&Robot_Chassis_Exp, sizeof(Remote_Chassis_Exp_));
    ROS_INFO("X = %f,Y = %f,YAW = %f", Robot_Chassis_Exp.remote_speed_x, Robot_Chassis_Exp.remote_speed_y, Robot_Chassis_Exp.remote_speed_yaw);
    ROS_INFO("stop = %d,switch = %f", Robot_Chassis_Exp.remote_stop_flag, Robot_Chassis_Exp.switch_remote);

    // ROS_INFO("Robot is in navigation mode");

    vcom_user.Transmit(2, 2, serial_data_user);
}
int main(int argc, char *argv[])
{
    ros::init(argc, argv, "control_chassis");
    ros::NodeHandle nh;

    nh.getParam("Navigation_Mode_now", Navigation_Mode_now);

    ros::Subscriber subCmd_Vel = nh.subscribe<geometry_msgs::Twist>("/cmd_vel", 10, OdometryAndCmd_VelHandler);

    ros::Subscriber subJoystick = nh.subscribe<sensor_msgs::Joy> ("/joy", 5, joystickHandler);

    ROS_INFO("%d", Navigation_Mode_now);

    ros::spin();

    return 0;
}