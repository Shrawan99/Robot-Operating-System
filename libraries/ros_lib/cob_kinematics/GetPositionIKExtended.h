#ifndef _ROS_SERVICE_GetPositionIKExtended_h
#define _ROS_SERVICE_GetPositionIKExtended_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/duration.h"
#include "moveit_msgs/RobotState.h"
#include "moveit_msgs/MoveItErrorCodes.h"
#include "geometry_msgs/Pose.h"
#include "moveit_msgs/Constraints.h"
#include "moveit_msgs/PositionIKRequest.h"

namespace cob_kinematics
{

static const char GETPOSITIONIKEXTENDED[] = "cob_kinematics/GetPositionIKExtended";

  class GetPositionIKExtendedRequest : public ros::Msg
  {
    public:
      moveit_msgs::PositionIKRequest ik_request;
      moveit_msgs::Constraints constraints;
      geometry_msgs::Pose ik_pose;
      bool constraint_aware;
      ros::Duration timeout;

    GetPositionIKExtendedRequest():
      ik_request(),
      constraints(),
      ik_pose(),
      constraint_aware(0),
      timeout()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->ik_request.serialize(outbuffer + offset);
      offset += this->constraints.serialize(outbuffer + offset);
      offset += this->ik_pose.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_constraint_aware;
      u_constraint_aware.real = this->constraint_aware;
      *(outbuffer + offset + 0) = (u_constraint_aware.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->constraint_aware);
      *(outbuffer + offset + 0) = (this->timeout.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timeout.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timeout.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timeout.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timeout.sec);
      *(outbuffer + offset + 0) = (this->timeout.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timeout.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timeout.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timeout.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timeout.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->ik_request.deserialize(inbuffer + offset);
      offset += this->constraints.deserialize(inbuffer + offset);
      offset += this->ik_pose.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_constraint_aware;
      u_constraint_aware.base = 0;
      u_constraint_aware.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->constraint_aware = u_constraint_aware.real;
      offset += sizeof(this->constraint_aware);
      this->timeout.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->timeout.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timeout.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timeout.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->timeout.sec);
      this->timeout.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->timeout.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timeout.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timeout.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->timeout.nsec);
     return offset;
    }

    const char * getType(){ return GETPOSITIONIKEXTENDED; };
    const char * getMD5(){ return "4c4b89f5ef198c1cce5ba907b8b96b58"; };

  };

  class GetPositionIKExtendedResponse : public ros::Msg
  {
    public:
      moveit_msgs::RobotState solution;
      moveit_msgs::MoveItErrorCodes error_code;

    GetPositionIKExtendedResponse():
      solution(),
      error_code()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->solution.serialize(outbuffer + offset);
      offset += this->error_code.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->solution.deserialize(inbuffer + offset);
      offset += this->error_code.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETPOSITIONIKEXTENDED; };
    const char * getMD5(){ return "ad50fe5fa0ddb482909be313121ea148"; };

  };

  class GetPositionIKExtended {
    public:
    typedef GetPositionIKExtendedRequest Request;
    typedef GetPositionIKExtendedResponse Response;
  };

}
#endif
