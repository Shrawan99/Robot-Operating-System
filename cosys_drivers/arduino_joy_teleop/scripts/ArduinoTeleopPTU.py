#!/usr/bin/env python
# license removed for brevity
import rospy
from sensor_msgs.msg import Joy
#from geometry_msgs.msg import Twist
from std_msgs.msg import UInt16

class JoyToPTU:
	# static members
	angularIndex = 3
	linearIndex = 4
	def __init__(self):
		rospy.init_node('joy_to_ptu', anonymous=True)
		rospy.Subscriber("joy", Joy, self.joyCallback)
		self.pub = rospy.Publisher("/ptu/tilt",UInt16,queue_size=10)
		# spin() simply keeps python from exiting until this node is stopped
		rospy.spin()
	    
	def joyCallback(self,joy):
		tilt = UInt16()#cmd_vel = Twist()
		tilt.data = (joy.axes[self.linearIndex]+1)*520/2
		#cmd_vel.angular.z = joy.axes[self.angularIndex]
		self.pub.publish(tilt)#self.pub.publish(cmd_vel)
		
		rospy.loginfo(rospy.get_caller_id() + "I heard %s%s\n", joy.axes,tilt.data) 
		
		
if __name__ == "__main__":
	joyToPTU = JoyToPTU()
	
		
