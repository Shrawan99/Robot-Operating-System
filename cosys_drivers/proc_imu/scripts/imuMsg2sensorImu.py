#!/usr/bin/env python
# license removed for brevity
import rospy
from sensor_msgs.msg import Imu
from proc_imu.msg import imuMsg
from geometry_msgs.msg import Vector3Stamped
import std_msgs.msg

#offset values
ACCEL_X_OFFSET = 0#20
ACCEL_Y_OFFSET = 0#14
ACCEL_Z_OFFSET = 0#-272

GYRO_X_OFFSET = -21
GYRO_Y_OFFSET = 36
GYRO_Z_OFFSET = 0

MAGNETO_X_OFFSET = 0#0
MAGNETO_Y_OFFSET = 0#417
MAGNETO_Z_OFFSET = 0#-33


from math import pi,sqrt
g=9.8
class ImuMsg2SensorImu:
	GYRO_SENSITIVITY = 14.375#in lsb /(degree/s)
	def __init__(self):
		rospy.init_node('imu_msg_to_sensor_imu', anonymous=True)
		rospy.Subscriber("imu_data", imuMsg, self.imuCallback)
		self.pubImu = rospy.Publisher("imu/data_raw",Imu,queue_size=1)
		self.pubMag = rospy.Publisher("imu/mag",Vector3Stamped,queue_size=1)
		# spin() simply keeps python from exiting until this node is stopped
		rospy.spin()
		
	def imuCallback(self,imuData):
		imu = Imu()
		imu.header.stamp = rospy.Time.now()
		imu.header.frame_id = "imu_frame"#"imu_frame"
		imu.angular_velocity.x = -(imuData.gyro[0] - GYRO_X_OFFSET)/self.GYRO_SENSITIVITY*pi/180
		imu.angular_velocity.y = -(imuData.gyro[1] - GYRO_Y_OFFSET)/self.GYRO_SENSITIVITY*pi/180
		imu.angular_velocity.z = -(imuData.gyro[2] - GYRO_Z_OFFSET)/self.GYRO_SENSITIVITY*pi/180
		
		imu.orientation_covariance[0]=0.001
		imu.orientation_covariance[4]=0.001
		imu.orientation_covariance[8]=0.001

		imu.angular_velocity_covariance[0]=0.001
		imu.angular_velocity_covariance[4]=0.001
		imu.angular_velocity_covariance[8]=0.001


		x=-imuData.accel[0]
		y=-imuData.accel[1]
		z=-imuData.accel[2]
		effectiveG = sqrt(x**2 + y**2 + z**2)
		x = float(x)/effectiveG*g
		y = float(y)/effectiveG*g
		z = float(z)/effectiveG*g
	
		
		imu.linear_acceleration.x = x
		imu.linear_acceleration.y = y
		imu.linear_acceleration.z = z
		
		imu.linear_acceleration_covariance[0]=0.001
		imu.linear_acceleration_covariance[4]=0.001
		imu.linear_acceleration_covariance[8]=0.001
		
		mag = Vector3Stamped()
		mag.header.stamp = imu.header.stamp
		mag.header.frame_id = "imu_frame"
		mag.vector.x = imuData.magneto[0] - MAGNETO_X_OFFSET
		mag.vector.y = imuData.magneto[1] - MAGNETO_Y_OFFSET
		mag.vector.z = imuData.magneto[2] - MAGNETO_Z_OFFSET
		
		self.pubImu.publish(imu)
		self.pubMag.publish(mag)

if __name__ == '__main__':
	imu2Sensor = ImuMsg2SensorImu()
		
		
		
