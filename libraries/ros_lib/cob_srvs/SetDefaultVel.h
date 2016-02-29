#ifndef _ROS_SERVICE_SetDefaultVel_h
#define _ROS_SERVICE_SetDefaultVel_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/String.h"
#include "std_msgs/Bool.h"

namespace cob_srvs
{

static const char SETDEFAULTVEL[] = "cob_srvs/SetDefaultVel";

  class SetDefaultVelRequest : public ros::Msg
  {
    public:
      float default_vel;

    SetDefaultVelRequest():
      default_vel(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_default_vel;
      u_default_vel.real = this->default_vel;
      *(outbuffer + offset + 0) = (u_default_vel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_default_vel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_default_vel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_default_vel.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->default_vel);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_default_vel;
      u_default_vel.base = 0;
      u_default_vel.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_default_vel.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_default_vel.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_default_vel.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->default_vel = u_default_vel.real;
      offset += sizeof(this->default_vel);
     return offset;
    }

    const char * getType(){ return SETDEFAULTVEL; };
    const char * getMD5(){ return "06408962e6bcadda2e07880ad9dedbec"; };

  };

  class SetDefaultVelResponse : public ros::Msg
  {
    public:
      std_msgs::Bool success;
      std_msgs::String error_message;

    SetDefaultVelResponse():
      success(),
      error_message()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->success.serialize(outbuffer + offset);
      offset += this->error_message.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->success.deserialize(inbuffer + offset);
      offset += this->error_message.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SETDEFAULTVEL; };
    const char * getMD5(){ return "bdad515e8f4c013bd650d3407753d2b8"; };

  };

  class SetDefaultVel {
    public:
    typedef SetDefaultVelRequest Request;
    typedef SetDefaultVelResponse Response;
  };

}
#endif
