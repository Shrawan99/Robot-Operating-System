#ifndef _ROS_cob_light_SetLightModeAction_h
#define _ROS_cob_light_SetLightModeAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "cob_light/SetLightModeActionGoal.h"
#include "cob_light/SetLightModeActionResult.h"
#include "cob_light/SetLightModeActionFeedback.h"

namespace cob_light
{

  class SetLightModeAction : public ros::Msg
  {
    public:
      cob_light::SetLightModeActionGoal action_goal;
      cob_light::SetLightModeActionResult action_result;
      cob_light::SetLightModeActionFeedback action_feedback;

    SetLightModeAction():
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

    const char * getType(){ return "cob_light/SetLightModeAction"; };
    const char * getMD5(){ return "1848f463649f84d5f3aa969db7b4a4fb"; };

  };

}
#endif