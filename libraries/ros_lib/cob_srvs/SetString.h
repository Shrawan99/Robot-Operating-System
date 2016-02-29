#ifndef _ROS_SERVICE_SetString_h
#define _ROS_SERVICE_SetString_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/String.h"

namespace cob_srvs
{

static const char SETSTRING[] = "cob_srvs/SetString";

  class SetStringRequest : public ros::Msg
  {
    public:
      const char* data;

    SetStringRequest():
      data("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_data = strlen(this->data);
      memcpy(outbuffer + offset, &length_data, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->data, length_data);
      offset += length_data;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_data;
      memcpy(&length_data, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_data; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_data-1]=0;
      this->data = (char *)(inbuffer + offset-1);
      offset += length_data;
     return offset;
    }

    const char * getType(){ return SETSTRING; };
    const char * getMD5(){ return "992ce8a1687cec8c8bd883ec73ca41d1"; };

  };

  class SetStringResponse : public ros::Msg
  {
    public:
      bool success;
      std_msgs::String errorMessage;

    SetStringResponse():
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

    const char * getType(){ return SETSTRING; };
    const char * getMD5(){ return "c3b62f691308002270bd6702fd7da94b"; };

  };

  class SetString {
    public:
    typedef SetStringRequest Request;
    typedef SetStringResponse Response;
  };

}
#endif
