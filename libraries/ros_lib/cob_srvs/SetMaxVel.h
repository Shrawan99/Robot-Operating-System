#ifndef _ROS_SERVICE_SetMaxVel_h
#define _ROS_SERVICE_SetMaxVel_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/String.h"

namespace cob_srvs
{

static const char SETMAXVEL[] = "cob_srvs/SetMaxVel";

  class SetMaxVelRequest : public ros::Msg
  {
    public:
      float max_vel;

    SetMaxVelRequest():
      max_vel(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_max_vel;
      u_max_vel.real = this->max_vel;
      *(outbuffer + offset + 0) = (u_max_vel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_vel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_vel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_vel.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_vel);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_max_vel;
      u_max_vel.base = 0;
      u_max_vel.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_vel.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_vel.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_vel.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_vel = u_max_vel.real;
      offset += sizeof(this->max_vel);
     return offset;
    }

    const char * getType(){ return SETMAXVEL; };
    const char * getMD5(){ return "dd4c36ffe76b55c7212cbc93d9e269be"; };

  };

  class SetMaxVelResponse : public ros::Msg
  {
    public:
      bool success;
      std_msgs::String errorMessage;

    SetMaxVelResponse():
      success(0),
      errorMessage()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      offset += this->errorMessage.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
      offset += this->errorMessage.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SETMAXVEL; };
    const char * getMD5(){ return "c3b62f691308002270bd6702fd7da94b"; };

  };

  class SetMaxVel {
    public:
    typedef SetMaxVelRequest Request;
    typedef SetMaxVelResponse Response;
  };

}
#endif
