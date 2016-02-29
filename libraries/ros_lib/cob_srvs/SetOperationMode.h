#ifndef _ROS_SERVICE_SetOperationMode_h
#define _ROS_SERVICE_SetOperationMode_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/String.h"
#include "std_msgs/Bool.h"

namespace cob_srvs
{

static const char SETOPERATIONMODE[] = "cob_srvs/SetOperationMode";

  class SetOperationModeRequest : public ros::Msg
  {
    public:
      std_msgs::String operation_mode;

    SetOperationModeRequest():
      operation_mode()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->operation_mode.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->operation_mode.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SETOPERATIONMODE; };
    const char * getMD5(){ return "df954cef597fce5b749fee53c7846c40"; };

  };

  class SetOperationModeResponse : public ros::Msg
  {
    public:
      std_msgs::Bool success;
      std_msgs::String error_message;

    SetOperationModeResponse():
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

    const char * getType(){ return SETOPERATIONMODE; };
    const char * getMD5(){ return "bdad515e8f4c013bd650d3407753d2b8"; };

  };

  class SetOperationMode {
    public:
    typedef SetOperationModeRequest Request;
    typedef SetOperationModeResponse Response;
  };

}
#endif
