#ifndef _ROS_SERVICE_SetJointStiffness_h
#define _ROS_SERVICE_SetJointStiffness_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/String.h"
#include "std_msgs/Bool.h"

namespace cob_srvs
{

static const char SETJOINTSTIFFNESS[] = "cob_srvs/SetJointStiffness";

  class SetJointStiffnessRequest : public ros::Msg
  {
    public:
      uint8_t joint_stiffness_length;
      float st_joint_stiffness;
      float * joint_stiffness;

    SetJointStiffnessRequest():
      joint_stiffness_length(0), joint_stiffness(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = joint_stiffness_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < joint_stiffness_length; i++){
      union {
        float real;
        uint32_t base;
      } u_joint_stiffnessi;
      u_joint_stiffnessi.real = this->joint_stiffness[i];
      *(outbuffer + offset + 0) = (u_joint_stiffnessi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_joint_stiffnessi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_joint_stiffnessi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_joint_stiffnessi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->joint_stiffness[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t joint_stiffness_lengthT = *(inbuffer + offset++);
      if(joint_stiffness_lengthT > joint_stiffness_length)
        this->joint_stiffness = (float*)realloc(this->joint_stiffness, joint_stiffness_lengthT * sizeof(float));
      offset += 3;
      joint_stiffness_length = joint_stiffness_lengthT;
      for( uint8_t i = 0; i < joint_stiffness_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_joint_stiffness;
      u_st_joint_stiffness.base = 0;
      u_st_joint_stiffness.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_joint_stiffness.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_joint_stiffness.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_joint_stiffness.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_joint_stiffness = u_st_joint_stiffness.real;
      offset += sizeof(this->st_joint_stiffness);
        memcpy( &(this->joint_stiffness[i]), &(this->st_joint_stiffness), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return SETJOINTSTIFFNESS; };
    const char * getMD5(){ return "3f30c4d99702f028fe1bef65668a3d21"; };

  };

  class SetJointStiffnessResponse : public ros::Msg
  {
    public:
      std_msgs::Bool success;
      std_msgs::String error_message;

    SetJointStiffnessResponse():
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

    const char * getType(){ return SETJOINTSTIFFNESS; };
    const char * getMD5(){ return "bdad515e8f4c013bd650d3407753d2b8"; };

  };

  class SetJointStiffness {
    public:
    typedef SetJointStiffnessRequest Request;
    typedef SetJointStiffnessResponse Response;
  };

}
#endif
