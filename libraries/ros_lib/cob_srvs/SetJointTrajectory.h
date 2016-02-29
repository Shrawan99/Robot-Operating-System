#ifndef _ROS_SERVICE_SetJointTrajectory_h
#define _ROS_SERVICE_SetJointTrajectory_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "trajectory_msgs/JointTrajectory.h"
#include "std_msgs/String.h"

namespace cob_srvs
{

static const char SETJOINTTRAJECTORY[] = "cob_srvs/SetJointTrajectory";

  class SetJointTrajectoryRequest : public ros::Msg
  {
    public:
      trajectory_msgs::JointTrajectory trajectory;

    SetJointTrajectoryRequest():
      trajectory()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->trajectory.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->trajectory.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SETJOINTTRAJECTORY; };
    const char * getMD5(){ return "2a0eff76c870e8595636c2a562ca298e"; };

  };

  class SetJointTrajectoryResponse : public ros::Msg
  {
    public:
      int64_t success;
      std_msgs::String errorMessage;

    SetJointTrajectoryResponse():
      success(0),
      errorMessage()
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
      offset += this->errorMessage.serialize(outbuffer + offset);
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
      offset += this->errorMessage.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SETJOINTTRAJECTORY; };
    const char * getMD5(){ return "fff2fd61c570b3016de5f27e6dc433be"; };

  };

  class SetJointTrajectory {
    public:
    typedef SetJointTrajectoryRequest Request;
    typedef SetJointTrajectoryResponse Response;
  };

}
#endif
