#!/usr/bin/env python
# license removed for brevity
import rospy
from proc_imu.msg import imuMsg


class CalculateOffset:
	def __init__(self,noOfSamples=100):
		self.noOfSamples = noOfSamples
		self.currentSample = 0
		#buffer for imu data
		self.acceleroTemp=[]
		self.gyroTemp = []
		self.magnetoTemp = []
		
		rospy.init_node('calculate_offset',anonymous=True)
		rospy.Subscriber("imu_data", imuMsg, self.imuCallback)
		self.pubOffset = rospy.Publisher("imu/offset",imuMsg,queue_size=1)
		# spin() simply keeps python from exiting until this node is stopped
		rospy.spin()
			
	
	
	def imuCallback(self,imuData):
		#print "callback"
		self.currentSample+=1			
			
		self.acceleroTemp.append((imuData.accel[0],imuData.accel[1],imuData.accel[2]))
		self.gyroTemp.append((imuData.gyro[0],imuData.gyro[1],imuData.gyro[2]))
		self.magnetoTemp.append((imuData.magneto[0],imuData.magneto[1],imuData.magneto[2]))
			
		
		
		if self.currentSample==self.noOfSamples:
			accelAvg = []
			gyroAvg = []
			magnetoAvg = []
			
			print len(self.acceleroTemp)
			for i in range(3):
				accelAvg.append(sum([self.acceleroTemp[j][i] for j in range(self.noOfSamples)])/float(self.noOfSamples))
			
			for i in range(3):
				gyroAvg.append(sum([self.gyroTemp[j][i] for j in range(self.noOfSamples)])/float(self.noOfSamples))
			
			for i in range(3):
				magnetoAvg.append(sum([self.magnetoTemp[j][i] for j in range(self.noOfSamples)])/float(self.noOfSamples))
				
			offset = imuMsg()
			offset.accel = accelAvg
			offset.gyro = gyroAvg
			offset.magneto = magnetoAvg
			
			
			self.pubOffset.publish(offset)
			
			"""reset the temp values"""
			self.currentSample = 0
			self.acceleroTemp=[]
			self.gyroTemp = []
			self.magnetoTemp = []
			
if __name__ == '__main__':
	offsetCalculator = CalculateOffset()
			
				
			
			
		
		
		
		
		
		
		
		
		
		
