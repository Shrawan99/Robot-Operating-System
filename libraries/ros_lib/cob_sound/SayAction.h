#ifndef _ROS_cob_sound_SayAction_h
#define _ROS_cob_sound_SayAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "cob_sound/SayActionGoal.h"
#include "cob_sound/SayActionResult.h"
#include "cob_sound/SayActionFeedback.h"

namespace cob_sound
{

  class SayAction : public ros::Msg
  {
    public:
      cob_sound::SayActionGoal action_goal;
      cob_sound::SayActionResult action_result;
      cob_sound::SayActionFeedback action_feedback;

    SayAction():
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

    const char * getType(){ return "cob_sound/SayAction"; };
    const char * getMD5(){ return "831241a2715cf9dd9da50b7c065ff283"; };

  };

}
#endif