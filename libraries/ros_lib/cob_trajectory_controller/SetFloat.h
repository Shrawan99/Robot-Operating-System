#ifndef _ROS_SERVICE_SetFloat_h
#define _ROS_SERVICE_SetFloat_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Float64.h"
#include "std_msgs/Bool.h"

namespace cob_trajectory_controller
{

static const char SETFLOAT[] = "cob_trajectory_controller/SetFloat";

  class SetFloatRequest : public ros::Msg
  {
    public:
      std_msgs::Float64 value;

    SetFloatRequest():
      value()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->value.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->value.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SETFLOAT; };
    const char * getMD5(){ return "1b2e6c76ff0a23e68a43b77651f66f18"; };

  };

  class SetFloatResponse : public ros::Msg
  {
    public:
      std_msgs::Bool success;

    SetFloatResponse():
      success()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->success.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->success.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SETFLOAT; };
    const char * getMD5(){ return "5f31cb2e813cfb0e488c574c3b5d9dbe"; };

  };

  class SetFloat {
    public:
    typedef SetFloatRequest Request;
    typedef SetFloatResponse Response;
  };

}
#endif
