#ifndef _ROS_SERVICE_GetPoseStampedTransformed_h
#define _ROS_SERVICE_GetPoseStampedTransformed_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/Quaternion.h"

namespace cob_srvs
{

static const char GETPOSESTAMPEDTRANSFORMED[] = "cob_srvs/GetPoseStampedTransformed";

  class GetPoseStampedTransformedRequest : public ros::Msg
  {
    public:
      geometry_msgs::PoseStamped target;
      geometry_msgs::PoseStamped origin;
      geometry_msgs::Quaternion orientation_override;
      const char* root_name;
      const char* tip_name;

    GetPoseStampedTransformedRequest():
      target(),
      origin(),
      orientation_override(),
      root_name(""),
      tip_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->target.serialize(outbuffer + offset);
      offset += this->origin.serialize(outbuffer + offset);
      offset += this->orientation_override.serialize(outbuffer + offset);
      uint32_t length_root_name = strlen(this->root_name);
      memcpy(outbuffer + offset, &length_root_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->root_name, length_root_name);
      offset += length_root_name;
      uint32_t length_tip_name = strlen(this->tip_name);
      memcpy(outbuffer + offset, &length_tip_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->tip_name, length_tip_name);
      offset += length_tip_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->target.deserialize(inbuffer + offset);
      offset += this->origin.deserialize(inbuffer + offset);
      offset += this->orientation_override.deserialize(inbuffer + offset);
      uint32_t length_root_name;
      memcpy(&length_root_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_root_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_root_name-1]=0;
      this->root_name = (char *)(inbuffer + offset-1);
      offset += length_root_name;
      uint32_t length_tip_name;
      memcpy(&length_tip_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_tip_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_tip_name-1]=0;
      this->tip_name = (char *)(inbuffer + offset-1);
      offset += length_tip_name;
     return offset;
    }

    const char * getType(){ return GETPOSESTAMPEDTRANSFORMED; };
    const char * getMD5(){ return "7f6050054c7441aa5c8e1b131c78c448"; };

  };

  class GetPoseStampedTransformedResponse : public ros::Msg
  {
    public:
      bool success;
      geometry_msgs::PoseStamped result;

    GetPoseStampedTransformedResponse():
      success(0),
      result()
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
      offset += this->result.serialize(outbuffer + offset);
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
      offset += this->result.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETPOSESTAMPEDTRANSFORMED; };
    const char * getMD5(){ return "aa1ecfaaa2557395e49e336255c7a317"; };

  };

  class GetPoseStampedTransformed {
    public:
    typedef GetPoseStampedTransformedRequest Request;
    typedef GetPoseStampedTransformedResponse Response;
  };

}
#endif
