#ifndef _ROS_cob_grasp_generation_QueryGraspsAction_h
#define _ROS_cob_grasp_generation_QueryGraspsAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "cob_grasp_generation/QueryGraspsActionGoal.h"
#include "cob_grasp_generation/QueryGraspsActionResult.h"
#include "cob_grasp_generation/QueryGraspsActionFeedback.h"

namespace cob_grasp_generation
{

  class QueryGraspsAction : public ros::Msg
  {
    public:
      cob_grasp_generation::QueryGraspsActionGoal action_goal;
      cob_grasp_generation::QueryGraspsActionResult action_result;
      cob_grasp_generation::QueryGraspsActionFeedback action_feedback;

    QueryGraspsAction():
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

    const char * getType(){ return "cob_grasp_generation/QueryGraspsAction"; };
    const char * getMD5(){ return "1ff93f6ea34d66c5322cd3f2f54d29e3"; };

  };

}
#endif