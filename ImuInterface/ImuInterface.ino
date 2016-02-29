#include <Wire.h>
#include <imu_9dof.h>

#include <ros.h>
#include <proc_imu/imuMsg.h>y

ros::NodeHandle  nh;

proc_imu::imuMsg imuData;

ros::Publisher imuPub("imu_data", &imuData);

IMU imu;

void setup()
{
  pinMode(13, OUTPUT);
  imu.begin();
  nh.initNode();
  nh.advertise(imuPub);
}

void loop(){  
  int *accelero,*gyro,*magneto;
  accelero = imu.accelRead();
  gyro = imu.gyroRead();
  magneto = imu.magnetomRead();

  imuData.accel[0]=accelero[0];
  imuData.accel[1]=accelero[1];
  imuData.accel[2]=accelero[2];
  
  imuData.gyro[0]=gyro[0];
  imuData.gyro[1]=gyro[1];
  imuData.gyro[2]=gyro[2];

  imuData.magneto[0]=magneto[0];
  imuData.magneto[1]=magneto[1];
  imuData.magneto[2]=magneto[2];

  imuPub.publish(&imuData);

  nh.spinOnce();
  delay(10);

}

