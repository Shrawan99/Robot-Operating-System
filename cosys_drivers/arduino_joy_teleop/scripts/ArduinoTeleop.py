#!/usr/bin/env python
# license removed for brevity
import rospy
from sensor_msgs.msg import Joy
from geometry_msgs.msg import Twist
from turtle_actionlib.msg import Velocity

class JoyToTwist:
	# static members
	angularIndex = 0	# joy.axes[0]
	linearIndex = 1		# joy.axes[1]
	enable = 0 		# joy.buttons[0] engage PTU when set 1 engage wheel when set 0 
	def __init__(self):
		rospy.init_node('joy_to_twist', anonymous=True)
		rospy.Subscriber("joy", Joy, self.joyCallback)
		self.pub = rospy.Publisher("wheelchair/command_velocity",Velocity,queue_size=10)#rospy.Publisher("cmd_vel",Twist,queue_size=10)
		# spin() simply keeps python from exiting until this node is stopped
		self.velocity = Velocity()
		#rospy.spin()

	def publish(self):
		self.pub.publish(self.velocity)
	    
	def joyCallback(self,joy):
		cmd_vel = Twist()
		self.velocity.linear = joy.axes[self.linearIndex]
		self.velocity.angular = joy.axes[self.angularIndex]
		cmd_vel.linear.x = joy.axes[self.linearIndex]
		cmd_vel.angular.z = joy.axes[self.angularIndex]
		#self.pub.publish(cmd_vel)
		#self.pub.publish(velocity)
		#rospy.loginfo(rospy.get_caller_id() + "I heard %s %s\n",velocity.linear,velocity.angular);
	#rospy.loginfo(rospy.get_caller_id() + "I heard %s %s\n", joy.axes,(cmd_vel.linear.x,cmd_vel.angular.z)) 
		

		
if __name__ == "__main__":
        joyToTwist = JoyToTwist()
        rate = rospy.Rate(10) # 10hz
        while not rospy.is_shutdown():
                rospy.loginfo(rospy.get_caller_id() + "I heard %s %s\n",joyToTwist.velocity.linear,joyToTwist.velocity.angular);
                joyToTwist.publish()
                rate.sleep()



