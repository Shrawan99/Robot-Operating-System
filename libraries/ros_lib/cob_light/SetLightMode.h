#ifndef _ROS_SERVICE_SetLightMode_h
#define _ROS_SERVICE_SetLightMode_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "cob_light/LightMode.h"

namespace cob_light
{

static const char SETLIGHTMODE[] = "cob_light/SetLightMode";

  class SetLightModeRequest : public ros::Msg
  {
    public:
      cob_light::LightMode mode;

    SetLightModeRequest():
      mode()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->mode.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->mode.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SETLIGHTMODE; };
    const char * getMD5(){ return "bfc3763d6f527fc6f26b234ea07ebf58"; };

  };

  class SetLightModeResponse : public ros::Msg
  {
    public:
      uint8_t active_mode;
      uint8_t active_priority;

    SetLightModeResponse():
      active_mode(0),
      active_priority(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->active_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->active_mode);
      *(outbuffer + offset + 0) = (this->active_priority >> (8 * 0)) & 0xFF;
      offset += sizeof(this->active_priority);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->active_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->active_mode);
      this->active_priority =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->active_priority);
     return offset;
    }

    const char * getType(){ return SETLIGHTMODE; };
    const char * getMD5(){ return "18daff0db423efd323f68cd039226daa"; };

  };

  class SetLightMode {
    public:
    typedef SetLightModeRequest Request;
    typedef SetLightModeResponse Response;
  };

}
#endif
