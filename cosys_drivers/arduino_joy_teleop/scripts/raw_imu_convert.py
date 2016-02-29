#!/usr/bin/env python
# license removed for brevity
import rospy
from geometry_msgs.msgs import Vector3
from sensor_msgs.msgs import Imu

class RawToIMU:
	def __init__(self):
		rospy.init_node('raw_to_imu',anoymous=True)
		rospy.Subscriber("accel",Vector3,self
