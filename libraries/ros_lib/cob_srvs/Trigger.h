#ifndef _ROS_SERVICE_Trigger_h
#define _ROS_SERVICE_Trigger_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/String.h"
#include "std_msgs/Bool.h"

namespace cob_srvs
{

static const char TRIGGER[] = "cob_srvs/Trigger";

  class TriggerRequest : public ros::Msg
  {
    public:

    TriggerRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return TRIGGER; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class TriggerResponse : public ros::Msg
  {
    public:
      std_msgs::Bool success;
      std_msgs::String error_message;

    TriggerResponse():
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

    const char * getType(){ return TRIGGER; };
    const char * getMD5(){ return "bdad515e8f4c013bd650d3407753d2b8"; };

  };

  class Trigger {
    public:
    typedef TriggerRequest Request;
    typedef TriggerResponse Response;
  };

}
#endif
