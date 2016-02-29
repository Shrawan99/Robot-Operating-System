#ifndef _ROS_cob_grasp_generation_GenerateGraspsAction_h
#define _ROS_cob_grasp_generation_GenerateGraspsAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "cob_grasp_generation/GenerateGraspsActionGoal.h"
#include "cob_grasp_generation/GenerateGraspsActionResult.h"
#include "cob_grasp_generation/GenerateGraspsActionFeedback.h"

namespace cob_grasp_generation
{

  class GenerateGraspsAction : public ros::Msg
  {
    public:
      cob_grasp_generation::GenerateGraspsActionGoal action_goal;
      cob_grasp_generation::GenerateGraspsActionResult action_result;
      cob_grasp_generation::GenerateGraspsActionFeedback action_feedback;

    GenerateGraspsAction():
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

    const char * getType(){ return "cob_grasp_generation/GenerateGraspsAction"; };
    const char * getMD5(){ return "89a87a049b703591da4f049707ec8fb4"; };

  };

}
#endif