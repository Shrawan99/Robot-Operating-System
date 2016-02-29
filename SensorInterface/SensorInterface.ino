#define LED 13
#define BATTERY12 A6
#define BATTERY24 A5
//definitions for encoder
#include <Encoder.h>
#include "Encoders.h"
#define rClick encoder1.noOfClick
#define lClick encoder2.noOfClick

Encoder encoder1(ENC1_INT_PIN,ENC1_DIR_PIN),encoder2(ENC2_INT_PIN,ENC2_DIR_PIN);

//definitions for PTU
#include <DynamixelSerialMega.h>
#include <std_msgs/Float32.h>
#include <std_msgs/UInt16.h>
#include <proc_ptu/ptuMsg.h>
#include "PTU.h"

/*
void tiltCallback(const std_msgs::Float32& commandTilt){
  unsigned int tilt;
  tilt = MIN_TILT + (MAX_TILT - MIN_TILT)/(2)*(commandTilt.data+1);//two point form of a line x1=-1,x2=-2,x= commandTilt.data
  Dynamixel.move(TILT_ID,tilt);
}

void panCallback(const std_msgs::Float32& commandPan){
  unsigned int pan;
  pan = MIN_PAN + (MAX_PAN - MIN_PAN)/(2)*(commandPan.data+1);//two point form of a line x1=-1,x2=-2,x= commandPan.data
  Dynamixel.move(PAN_ID,pan);
}
*/


//for IMU
#include <Wire.h>
#include <imu_9dof.h>
IMU imu;

//for motors
#include "Motors.h"
#include <Servo.h>
#include <turtle_actionlib/Velocity.h>
Servo servoLeft,servoRight;




//for ros
#include <ros.h>
#include <std_msgs/Int16.h>
#include <proc_odom/odomMsg.h>
#include <proc_imu/imuMsg.h>
#include <ros/time.h>

void ptuCallback(const  proc_ptu::ptuMsg& command)
{
  unsigned int tilt;
  unsigned int pan;
  
  tilt = (long)MIN_TILT + ((long)MAX_TILT - MIN_TILT)*((long)command.tilt - MIN_PTU_COMMAND)/((long)MAX_PTU_COMMAND - MIN_PTU_COMMAND);
  pan = (long)MIN_PAN + ((long)MAX_PAN - MIN_PAN)*((long)command.pan - MIN_PTU_COMMAND)/((long)MAX_PTU_COMMAND - MIN_PTU_COMMAND);
  Dynamixel.move(TILT_ID,tilt);
  Dynamixel.move(PAN_ID,pan);
}

std_msgs::UInt16 battery12_level;
std_msgs::UInt16 battery24_level;

void servoCallback(const turtle_actionlib::Velocity& vel)
{
  if(battery24_level.data>0)
  {
    servoRight.write(HALT_PWM - (vel.linear+vel.angular)/(2*MAX_VEL)*HALT_PWM);
    servoLeft.write(HALT_PWM - (vel.linear-vel.angular)/(2*MAX_VEL)*HALT_PWM);
  }
  else
  {
    servoRight.write(HALT_PWM); //90 means halt
    servoLeft.write(HALT_PWM); //90 means servo halt

  }
}



ros::NodeHandle nh;
proc_imu::imuMsg imuData;
proc_odom::odomMsg encoderClick;
proc_ptu::ptuMsg ptuFeedback;

//std_msgs::Float32 tilt;//TODO: proper msg type for gyro data
//std_msgs::Float32 pan;
std_msgs::Float32 cmdVelLinear;
std_msgs::Float32 cmdVelAngular;

ros::Publisher encPub("encoder_click", &encoderClick);
ros::Publisher imuPub("imu_data", &imuData);
ros::Publisher battery12Pub("battery12_data", &battery12_level);
ros::Publisher battery24Pub("battery24_data", &battery24_level);
ros::Publisher ptuPub("ptu_msg",&ptuFeedback);

//deprecated
//ros::Subscriber<std_msgs::Float32> subTilt("ptu/tilt", &tiltCallback);
//ros::Subscriber<std_msgs::Float32> subPan("ptu/pan", &panCallback);
ros::Subscriber<proc_ptu::ptuMsg> subPTU("cmd_ptu", &ptuCallback);
ros::Subscriber<turtle_actionlib::Velocity> subCmdVel("wheelchair/command_velocity", &servoCallback);

//TODO: use this for interpolation for ptuCallback
unsigned int linearInterpolation(unsigned int x, unsigned int x1, unsigned int x2, unsigned int y1, unsigned int y2){
  return ((long)y1 + ((long)y2 - y1)*((long)x - x1)/((long)x2 - x));
}




void setup()
{
  pinMode(LED,OUTPUT);
  pinMode(BATTERY12,INPUT);
  pinMode(BATTERY24,INPUT);
  
  //for PTU
  Dynamixel.begin(1000000,PTU_DATA_SELECT);  // Initialize the servo at 1Mbps and Pin Control 2
  Dynamixel.turn(TILT_ID,0,100);//set speed
  Dynamixel.turn(PAN_ID,0,100);//set speed
  
  //for encoder
  attachInterrupt(ENC1_INT_CHANNEL, enc1PulseIncrement, FALLING);
  attachInterrupt(ENC2_INT_CHANNEL, enc2PulseIncrement, FALLING);
  interrupts();//enable the interrupts
  
  //for IMU
  imu.begin();//Wire.begin();
  //imu.gyroInit();
  
  //motor
  servoLeft.attach(LEFT_MOTOR);
  servoRight.attach(RIGHT_MOTOR);
  
  
  nh.initNode();
  nh.advertise(encPub);
  nh.advertise(imuPub);
  nh.advertise(ptuPub);
  nh.advertise(battery12Pub);
  nh.advertise(battery24Pub);
  //deprecated
  //nh.subscribe(subTilt);
  //nh.subscribe(subPan);
  //new implementation
  nh.subscribe(subPTU);
  nh.subscribe(subCmdVel);
  delay(500);
}

void loop(){
  //Serial.println(digitalRead(5));
  //.return;
  
  //the encoder increment has been implemented in ISR itself
  /*
  if (encoder1.intReceived()){
    encoder1.increment();//debounced implementation
  }
  if (encoder2.intReceived()){
    encoder2.increment();//debounced implementation
  }
  */
    
  
  if ((millis()%100)==0){//publish
    //encoder
    battery12_level.data=analogRead(BATTERY12);
    battery24_level.data=analogRead(BATTERY24);
    battery12Pub.publish(&battery12_level);
    battery24Pub.publish(&battery24_level);
    
    int temp1 = lClick,temp2 = rClick;
    lClick = rClick = 0;
    encoderClick.lclicks=-temp2;
    encoderClick.rclicks=-temp1;
    //TODO: get the new message definition for encoder click
    encoderClick.t=nh.now();
    
    encPub.publish(&encoderClick);
    
    //ptu
    int pan,tilt;
    pan = Dynamixel.readPosition(PAN_ID);
    tilt = Dynamixel.readPosition(TILT_ID);
    //only if the feedback is valid, we publish
    if(pan>=MIN_PAN && pan<=MAX_PAN && tilt>=MIN_TILT && tilt<=MAX_TILT){
      ptuFeedback.pan = pan;
      ptuFeedback.tilt = tilt;
    
      ptuPub.publish(&ptuFeedback);
    }
    
    //imu
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
          
  }
  
  if((millis()%2)==0){
    nh.spinOnce();
  }
}


void enc1PulseIncrement()
{
  
 //encoder1.check();//deprecated
 encoder1.increment();
  //Serial.println("int");
}

void enc2PulseIncrement(){
  //encoder2.check();//deprecated
  encoder2.increment();
}


