#!/usr/bin/env python

from __future__ import division
import roslib; 
roslib.load_manifest('proc_odom')
import rospy

from std_msgs.msg import String

from proc_odom.msg import odomMsg
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Quaternion

import time
from tf.transformations import euler_from_quaternion
import tf

import numpy as np


radius = 0.26#507
wheel_gap = 0.615
perClick = 0.046258224

def OdomMsgCallback(odomMsg_):
    global odom_t0; global x; global y; global theta
    if odom_t0 != odomMsg_.t.to_sec():
        dx, dy, dtheta = RK4(odomMsg_.rclicks, odomMsg_.lclicks, (odomMsg_.t.to_sec()-odom_t0))
	#encoderL = odomMsg_.rclicks
	#encoderR = odomMsg_.lclicks	
	#dt = odomMsg_.t.to_sec()-odom_t0
        #v_l = (encoderL*np.pi*perClick)/(dt*180)
        #v_r = (encoderR*np.pi*perClick)/(dt*180)
	#lin_vel = ((v_l * radius) + (v_r * radius)) / 2.0
        #ang_vel = ((v_l * radius) - (v_r * radius)) / wheel_gap
        x += dx
        y += dy
        theta += dtheta
        odom_t0 = odomMsg_.t.to_sec()
        odom.header.stamp = odomMsg_.t
        odom.pose.pose.position.x = x
        odom.pose.pose.position.y = y
        odom.pose.pose.position.z = 0.0
	odom.pose.covariance[0]  = 0.0001;
	odom.pose.covariance[7]  = 0.0001;
	odom.pose.covariance[14] = 99999;
	odom.pose.covariance[21] = 99999;
	odom.pose.covariance[28] = 99999;
	odom.pose.covariance[35] = 0.0001;
        q = tf.transformations.quaternion_from_euler(0, 0, theta)
        odom.pose.pose.orientation = Quaternion(q[0], q[1], q[2], q[3])
        odom_pub.publish(odom)
	odom_t0 = rospy.get_time()
	

def RK4(encoderL, encoderR, dt):  
    global perClick; global radius; global theta
 
    v_l = (encoderL*np.pi*perClick)/(dt*180)
    v_r = (encoderR*np.pi*perClick)/(dt*180)

    lin_vel = ((v_l * radius) + (v_r * radius)) / 2.0
    ang_vel = ((v_l * radius) - (v_r * radius)) / wheel_gap
    
    k00 = lin_vel*np.cos(theta)
    k01 = lin_vel*np.sin(theta)
    k02 = ang_vel
    
    k10 = lin_vel*np.cos(theta+(dt*k02/2.0))
    k11 = lin_vel*np.sin(theta+(dt*k02/2.0))
    k12 = ang_vel
    
    k20 = lin_vel*np.cos(theta+(dt*k12/2.0))
    k21 = lin_vel*np.sin(theta+(dt*k12/2.0))
    k22 = ang_vel
    
    k30 = lin_vel*np.cos(theta+(dt*k22))
    k31 = lin_vel*np.sin(theta+(dt*k22))
    k32 = ang_vel
    
    return dt*(k00+(2.0*k10)+(2.0*k20)+k30)/6.0, dt*(k01+(2.0*k11)+(2.0*k21)+k31)/6.0, dt*(k02+(2.0*k12)+(2.0*k22)+k32)/6.0




if __name__ == '__main__':
    rospy.init_node('odometry_publisher', anonymous=True)
    x, y, theta = 0, 0, 0
    odom_t0 = rospy.get_time()
    odom = Odometry()
    odom.header.frame_id = "odom"

    odom_pub = rospy.Publisher("/odom", Odometry)
    rospy.Subscriber("/encoder_click", odomMsg, OdomMsgCallback)
    rospy.spin()


