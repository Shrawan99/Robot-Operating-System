#ifndef _ROS_cob_pick_place_action_CobPickAction_h
#define _ROS_cob_pick_place_action_CobPickAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "cob_pick_place_action/CobPickActionGoal.h"
#include "cob_pick_place_action/CobPickActionResult.h"
#include "cob_pick_place_action/CobPickActionFeedback.h"

namespace cob_pick_place_action
{

  class CobPickAction : public ros::Msg
  {
    public:
      cob_pick_place_action::CobPickActionGoal action_goal;
      cob_pick_place_action::CobPickActionResult action_result;
      cob_pick_place_action::CobPickActionFeedback action_feedback;

    CobPickAction():
      action_goal(),
      action_result(),
      action_feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->action_goal.serialize(outbuffer + offset);
      offset += this->action_result.serialize(outbuffer + offset);
      offset += this->action_feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->action_goal.deserialize(inbuffer + offset);
      offset += this->action_result.deserialize(inbuffer + offset);
      offset += this->action_feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "cob_pick_place_action/CobPickAction"; };
    const char * getMD5(){ return "6427abc9bf423f9585e8fcd8f4677a72"; };

  };

}
#endif