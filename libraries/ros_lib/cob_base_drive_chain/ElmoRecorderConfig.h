#ifndef _ROS_SERVICE_ElmoRecorderConfig_h
#define _ROS_SERVICE_ElmoRecorderConfig_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cob_base_drive_chain
{

static const char ELMORECORDERCONFIG[] = "cob_base_drive_chain/ElmoRecorderConfig";

  class ElmoRecorderConfigRequest : public ros::Msg
  {
    public:
      int64_t recordinggap;

    ElmoRecorderConfigRequest():
      recordinggap(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_recordinggap;
      u_recordinggap.real = this->recordinggap;
      *(outbuffer + offset + 0) = (u_recordinggap.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_recordinggap.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_recordinggap.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_recordinggap.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_recordinggap.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_recordinggap.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_recordinggap.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_recordinggap.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->recordinggap);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_recordinggap;
      u_recordinggap.base = 0;
      u_recordinggap.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_recordinggap.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_recordinggap.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_recordinggap.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_recordinggap.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_recordinggap.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_recordinggap.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_recordinggap.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->recordinggap = u_recordinggap.real;
      offset += sizeof(this->recordinggap);
     return offset;
    }

    const char * getType(){ return ELMORECORDERCONFIG; };
    const char * getMD5(){ return "a1ce3cece03ba225e8f3c4cf2e9ad968"; };

  };

  class ElmoRecorderConfigResponse : public ros::Msg
  {
    public:
      int64_t success;
      const char* message;

    ElmoRecorderConfigResponse():
      success(0),
      message("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_success.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_success.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_success.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_success.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_success.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_success.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_success.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->success);
      uint32_t length_message = strlen(this->message);
      memcpy(outbuffer + offset, &length_message, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_success.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_success.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_success.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_success.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_success.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_success.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_success.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->success = u_success.real;
      offset += sizeof(this->success);
      uint32_t length_message;
      memcpy(&length_message, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
     return offset;
    }

    const char * getType(){ return ELMORECORDERCONFIG; };
    const char * getMD5(){ return "a223a80848aece692f82aeb7f4a04f7f"; };

  };

  class ElmoRecorderConfig {
    public:
    typedef ElmoRecorderConfigRequest Request;
    typedef ElmoRecorderConfigResponse Response;
  };

}
#endif
