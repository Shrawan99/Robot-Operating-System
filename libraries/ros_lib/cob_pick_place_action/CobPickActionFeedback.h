#ifndef _ROS_cob_pick_place_action_CobPickActionFeedback_h
#define _ROS_cob_pick_place_action_CobPickActionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "cob_pick_place_action/CobPickFeedback.h"

namespace cob_pick_place_action
{

  class CobPickActionFeedback : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalStatus status;
      cob_pick_place_action::CobPickFeedback feedback;

    CobPickActionFeedback():
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

    const char * getType(){ return "cob_pick_place_action/CobPickActionFeedback"; };
    const char * getMD5(){ return "a21053c909fe17610cde1960df547dd1"; };

  };

}
#endif