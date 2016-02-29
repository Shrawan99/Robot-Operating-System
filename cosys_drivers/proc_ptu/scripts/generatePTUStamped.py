#!/usr/bin/env python
# license removed for brevity
import rospy
from proc_ptu.msg import ptuMsg
from geometry_msgs.msg import Vector3Stamped

def linearInterpolation(x,x1,x2,y1,y2):
	return y1 + (float(y2) - y1)/(float(x2) - x1)*(float(x)-x1)

TILT_ZERO_POSITION = 200
PAN_ZERO_POSITION = 512
PTU_MIN_VALUE = 0
PTU_MAX_VALUE = 1023
PTU_MIN_ANGLE = 0
PTU_MAX_ANGLE = 300

class PtuMsg2PtuStamped:
	def __init__(self):
		rospy.init_node('ptu_msg_to_ptu_stamped', anonymous=True)
		rospy.Subscriber("ptu_msg", ptuMsg, self.ptuMsgCallback)
		self.pubStamped = rospy.Publisher("ptu_stamped",Vector3Stamped,queue_size=1)
		# spin() simply keeps python from exiting until this node is stopped
		rospy.spin()
	
	def ptuMsgCallback(self,ptuFeedback):
		ptuStamped = Vector3Stamped()
		ptuStamped.header.stamp = rospy.Time.now()
		panAngle = linearInterpolation((ptuFeedback.pan - PAN_ZERO_POSITION),PTU_MIN_VALUE,PTU_MAX_VALUE,PTU_MIN_ANGLE,PTU_MAX_ANGLE)
		tiltAngle = linearInterpolation((ptuFeedback.tilt - TILT_ZERO_POSITION),PTU_MIN_VALUE,PTU_MAX_VALUE,PTU_MIN_ANGLE,PTU_MAX_ANGLE)
		ptuStamped.vector.x = panAngle
		ptuStamped.vector.y = tiltAngle
		
		self.pubStamped.publish(ptuStamped)
		
if __name__ == "__main__":
	PtuMsg2PtuStamped()
		
		
		
