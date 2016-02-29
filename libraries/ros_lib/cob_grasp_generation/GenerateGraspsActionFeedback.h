#ifndef _ROS_cob_grasp_generation_GenerateGraspsActionFeedback_h
#define _ROS_cob_grasp_generation_GenerateGraspsActionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "cob_grasp_generation/GenerateGraspsFeedback.h"

namespace cob_grasp_generation
{

  class GenerateGraspsActionFeedback : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalStatus status;
      cob_grasp_generation::GenerateGraspsFeedback feedback;

    GenerateGraspsActionFeedback():
      header(),
      status(),
      feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "cob_grasp_generation/GenerateGraspsActionFeedback"; };
    const char * getMD5(){ return "9cb5139df91af03aeb0bb0b4540c91c9"; };

  };

}
#endif