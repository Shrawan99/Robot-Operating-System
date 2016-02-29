#!/usr/bin/env python
# license removed for brevity
import rospy
from sensor_msgs.msg import Joy
from proc_ptu.msg import ptuMsg

def linearInterpolation(x,x1,x2,y1,y2):
	return x1 + (y2-y1)/(x2-x1)*(x-x1)

class JoyToPTU2:
	# static members
	angularIndex = 0	# joy.axes 0
	linearIndex = 1		# joy.axes 1
	tiltIndex = 0
	panIndex = 1
	enable = 0 		# buttons 0 to engage PTU
	#command limits for PTU
	MIN_COMMAND = 0
	MAX_COMMAND = 1023
	
	def __init__(self):
		rospy.init_node('joy_to_ptu', anonymous=True)
		rospy.Subscriber("joy", Joy, self.joyCallback)
		self.pubPTU = rospy.Publisher("/ptu_msg",ptuMsg,queue_size=1)
		rospy.spin()
		
		rospy.loginfo(rospy.get_caller_id() + ":In constructor");
	    
	def joyCallback(self,joy):
		ptuCmd = ptuMsg()
		
		if joy.buttons[self.enable]:
			ptuCmd.tilt = linearInterpolation(-joy.axes[self.tiltIndex],-1,1,self.MIN_COMMAND,self.MAX_COMMAND)
			ptuCmd.pan = linearInterpolation(joy.axes[self.panIndex],-1,1,self.MIN_COMMAND,self.MAX_COMMAND)
		#cmd_vel.angular.z = joy.axes[self.angularIndex]
			self.pubPTU.publish(ptuCmd)
			rospy.loginfo(rospy.get_caller_id() + "I heard\n", ) 
			
	

		
		
if __name__ == "__main__":
	joyToPTU = JoyToPTU2()
