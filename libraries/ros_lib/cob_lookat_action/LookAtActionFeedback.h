#ifndef _ROS_cob_lookat_action_LookAtActionFeedback_h
#define _ROS_cob_lookat_action_LookAtActionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "cob_lookat_action/LookAtFeedback.h"

namespace cob_lookat_action
{

  class LookAtActionFeedback : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalStatus status;
      cob_lookat_action::LookAtFeedback feedback;

    LookAtActionFeedback():
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

    const char * getType(){ return "cob_lookat_action/LookAtActionFeedback"; };
    const char * getMD5(){ return "9cb5139df91af03aeb0bb0b4540c91c9"; };

  };

}
#endif