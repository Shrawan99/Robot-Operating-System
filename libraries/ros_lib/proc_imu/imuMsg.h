#ifndef _ROS_proc_imu_imuMsg_h
#define _ROS_proc_imu_imuMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace proc_imu
{

  class imuMsg : public ros::Msg
  {
    public:
      int16_t accel[3];
      int16_t gyro[3];
      int16_t magneto[3];

    imuMsg():
      accel(),
      gyro(),
      magneto()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint8_t i = 0; i < 3; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_acceli;
      u_acceli.real = this->accel[i];
      *(outbuffer + offset + 0) = (u_acceli.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_acceli.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->accel[i]);
      }
      for( uint8_t i = 0; i < 3; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_gyroi;
      u_gyroi.real = this->gyro[i];
      *(outbuffer + offset + 0) = (u_gyroi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gyroi.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->gyro[i]);
      }
      for( uint8_t i = 0; i < 3; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_magnetoi;
      u_magnetoi.real = this->magneto[i];
      *(outbuffer + offset + 0) = (u_magnetoi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_magnetoi.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->magneto[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint8_t i = 0; i < 3; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_acceli;
      u_acceli.base = 0;
      u_acceli.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_acceli.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->accel[i] = u_acceli.real;
      offset += sizeof(this->accel[i]);
      }
      for( uint8_t i = 0; i < 3; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_gyroi;
      u_gyroi.base = 0;
      u_gyroi.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gyroi.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->gyro[i] = u_gyroi.real;
      offset += sizeof(this->gyro[i]);
      }
      for( uint8_t i = 0; i < 3; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_magnetoi;
      u_magnetoi.base = 0;
      u_magnetoi.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_magnetoi.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->magneto[i] = u_magnetoi.real;
      offset += sizeof(this->magneto[i]);
      }
     return offset;
    }

    const char * getType(){ return "proc_imu/imuMsg"; };
    const char * getMD5(){ return "86b9519a7ff3650408a91c476c3f44bb"; };

  };

}
#endif