#ifndef _ROS_SERVICE_ElmoRecorderReadout_h
#define _ROS_SERVICE_ElmoRecorderReadout_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cob_base_drive_chain
{

static const char ELMORECORDERREADOUT[] = "cob_base_drive_chain/ElmoRecorderReadout";

  class ElmoRecorderReadoutRequest : public ros::Msg
  {
    public:
      int64_t subindex;
      const char* fileprefix;

    ElmoRecorderReadoutRequest():
      subindex(0),
      fileprefix("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_subindex;
      u_subindex.real = this->subindex;
      *(outbuffer + offset + 0) = (u_subindex.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_subindex.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_subindex.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_subindex.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_subindex.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_subindex.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_subindex.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_subindex.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->subindex);
      uint32_t length_fileprefix = strlen(this->fileprefix);
      memcpy(outbuffer + offset, &length_fileprefix, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->fileprefix, length_fileprefix);
      offset += length_fileprefix;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_subindex;
      u_subindex.base = 0;
      u_subindex.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_subindex.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_subindex.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_subindex.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_subindex.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_subindex.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_subindex.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_subindex.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->subindex = u_subindex.real;
      offset += sizeof(this->subindex);
      uint32_t length_fileprefix;
      memcpy(&length_fileprefix, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_fileprefix; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_fileprefix-1]=0;
      this->fileprefix = (char *)(inbuffer + offset-1);
      offset += length_fileprefix;
     return offset;
    }

    const char * getType(){ return ELMORECORDERREADOUT; };
    const char * getMD5(){ return "dd88752641c6995eb674ed67be4e41d1"; };

  };

  class ElmoRecorderReadoutResponse : public ros::Msg
  {
    public:
      int64_t success;
      const char* message;

    ElmoRecorderReadoutResponse():
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

    const char * getType(){ return ELMORECORDERREADOUT; };
    const char * getMD5(){ return "a223a80848aece692f82aeb7f4a04f7f"; };

  };

  class ElmoRecorderReadout {
    public:
    typedef ElmoRecorderReadoutRequest Request;
    typedef ElmoRecorderReadoutResponse Response;
  };

}
#endif
