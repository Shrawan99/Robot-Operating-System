#!/usr/bin/env python
# license removed for brevity
import rospy
from std_msgs.msg import String
from geometry_msgs.msg import Twist

class webTeleop:
	def __init__(self):
		rospy.init_node('web_teleop', anonymous=True)
		rospy.Subscriber("echo", String, self.webCallback)
		self.pub = rospy.Publisher("/turtlebot_node/cmd_vel",Twist,queue_size=10)
		self.cmd_vel = Twist()
		#rospy.spin()

	def publish(self):
		self.pub.publish(self.cmd_vel)
	    
	def webCallback(self,string):
		if(string.data == "w"):
			self.cmd_vel.linear.x += 0.1
		elif(string.data == "a"):
			self.cmd_vel.linear.z += 0.1
			self.cmd_vel.angular.z += 0.1
		elif(string.data == "s"):
			self.cmd_vel.linear.x -= 0.1
		elif(string.data == "d"):
			self.cmd_vel.linear.z -= 0.1
			self.cmd_vel.angular.z -= 0.1
		elif(string.data == "x"):
			self.cmd_vel.linear.x = 0
			self.cmd_vel.angular.z = 0
			self.cmd_vel.linear.z = 0				
		
if __name__ == "__main__":
        webTeleop = webTeleop()
        rate = rospy.Rate(10) # 10hz
        while not rospy.is_shutdown():
                webTeleop.publish()
                rate.sleep()



