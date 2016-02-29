#ifndef _ROS_proc_odom_odomMsg_h
#define _ROS_proc_odom_odomMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace proc_odom
{

  class odomMsg : public ros::Msg
  {
    public:
      int16_t lclicks;
      int16_t rclicks;
      ros::Time t;

    odomMsg():
      lclicks(0),
      rclicks(0),
      t()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_lclicks;
      u_lclicks.real = this->lclicks;
      *(outbuffer + offset + 0) = (u_lclicks.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lclicks.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->lclicks);
      union {
        int16_t real;
        uint16_t base;
      } u_rclicks;
      u_rclicks.real = this->rclicks;
      *(outbuffer + offset + 0) = (u_rclicks.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rclicks.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->rclicks);
      *(outbuffer + offset + 0) = (this->t.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->t.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->t.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->t.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->t.sec);
      *(outbuffer + offset + 0) = (this->t.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->t.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->t.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->t.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->t.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_lclicks;
      u_lclicks.base = 0;
      u_lclicks.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lclicks.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->lclicks = u_lclicks.real;
      offset += sizeof(this->lclicks);
      union {
        int16_t real;
        uint16_t base;
      } u_rclicks;
      u_rclicks.base = 0;
      u_rclicks.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rclicks.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->rclicks = u_rclicks.real;
      offset += sizeof(this->rclicks);
      this->t.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->t.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->t.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->t.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->t.sec);
      this->t.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->t.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->t.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->t.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->t.nsec);
     return offset;
    }

    const char * getType(){ return "proc_odom/odomMsg"; };
    const char * getMD5(){ return "a620160f082fe9693953045767d648f8"; };

  };

}
#endif