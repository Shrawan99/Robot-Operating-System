#ifndef _ROS_proc_ptu_ptuMsg_h
#define _ROS_proc_ptu_ptuMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace proc_ptu
{

  class ptuMsg : public ros::Msg
  {
    public:
      int16_t pan;
      int16_t tilt;

    ptuMsg():
      pan(0),
      tilt(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_pan;
      u_pan.real = this->pan;
      *(outbuffer + offset + 0) = (u_pan.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pan.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pan);
      union {
        int16_t real;
        uint16_t base;
      } u_tilt;
      u_tilt.real = this->tilt;
      *(outbuffer + offset + 0) = (u_tilt.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tilt.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->tilt);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_pan;
      u_pan.base = 0;
      u_pan.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pan.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pan = u_pan.real;
      offset += sizeof(this->pan);
      union {
        int16_t real;
        uint16_t base;
      } u_tilt;
      u_tilt.base = 0;
      u_tilt.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tilt.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->tilt = u_tilt.real;
      offset += sizeof(this->tilt);
     return offset;
    }

    const char * getType(){ return "proc_ptu/ptuMsg"; };
    const char * getMD5(){ return "e5401181ff33a9d514daeb8a647b3152"; };

  };

}
#endif