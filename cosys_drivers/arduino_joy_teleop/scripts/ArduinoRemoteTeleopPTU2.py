#!/usr/bin/env python
# license removed for brevity
import rospy
from sensor_msgs.msg import Joy
from std_msgs.msg import Float32
from geometry_msgs.msg import Twist
from proc_ptu.msg import ptuMsg
from math import atan2, sqrt, pi

def linearInterpolation(x,x1,x2,y1,y2):
	return y1 + (y2-y1)/(x2-x1)*(x-x1)

class JoyToPTU2:
	# static members
	angularIndex = 0	# joy.axes 0
	linearIndex = 1		# joy.axes 1
	tiltIndex = 1
	panIndex = 0
	enable = 0 		# buttons 0 to engage PTU
        move_base_enable = 1    #joy.buttons[5]
	#command limits for PTU
	MIN_COMMAND = -32677
	MAX_COMMAND = 32677
	
	def __init__(self):
		rospy.init_node('joy_to_ptu', anonymous=True)
		rospy.Subscriber("joy", Joy, self.joyCallback)
		rospy.Subscriber("cmd_vel",Twist, self.navCallback)
		self.pubPTU = rospy.Publisher("/cmd_ptu",ptuMsg,queue_size=1)
		self.joy_data = Joy()
		self.ptuCmd = ptuMsg()
	
	def publish(self):
		self.pubPTU.publish(self.ptuCmd)
	
	def navCallback(self,cmd_vel):
		if self.joy_data.buttons[self.move_base_enable] == 1:
			y = cmd_vel.angular.z
			x = cmd_vel.linear.x
			mag = sqrt(x**2 + y**2)/sqrt(2)
			theta = atan2(y,x+0.00001)
			self.ptuCmd.tilt = linearInterpolation(mag,0,1,self.MIN_COMMAND,self.MAX_COMMAND)
			self.ptuCmd.pan = linearInterpolation(theta,-pi,pi,self.MIN_COMMAND,self.MAX_COMMAND)
	    
	def joyCallback(self,joy):
		self.joy_data = joy
		tilt = Float32()
		pan = Float32()
		
		if self.joy_data.buttons[self.move_base_enable] == 0:
			y = joy.axes[self.angularIndex]
			x = joy.axes[self.linearIndex]
			mag = sqrt(x**2 + y**2)/sqrt(2)
			theta = atan2(y,x+0.00001)
			self.ptuCmd.tilt = linearInterpolation(mag,0,1,self.MIN_COMMAND,self.MAX_COMMAND)
			self.ptuCmd.pan = linearInterpolation(theta,-pi,pi,self.MIN_COMMAND,self.MAX_COMMAND)
		
		
if __name__ == "__main__":
	joyToPTU = JoyToPTU2()
	rate = rospy.Rate(10) # 10hz
        while not rospy.is_shutdown():
                rospy.loginfo(rospy.get_caller_id() + "I heard %s %s\n",joyToPTU.ptuCmd.pan,joyToPTU.ptuCmd.tilt);
                joyToPTU.publish()
                rate.sleep()

		
