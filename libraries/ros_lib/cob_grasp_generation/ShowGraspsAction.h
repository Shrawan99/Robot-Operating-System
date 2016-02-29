#ifndef _ROS_cob_grasp_generation_ShowGraspsAction_h
#define _ROS_cob_grasp_generation_ShowGraspsAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "cob_grasp_generation/ShowGraspsActionGoal.h"
#include "cob_grasp_generation/ShowGraspsActionResult.h"
#include "cob_grasp_generation/ShowGraspsActionFeedback.h"

namespace cob_grasp_generation
{

  class ShowGraspsAction : public ros::Msg
  {
    public:
      cob_grasp_generation::ShowGraspsActionGoal action_goal;
      cob_grasp_generation::ShowGraspsActionResult action_result;
      cob_grasp_generation::ShowGraspsActionFeedback action_feedback;

    ShowGraspsAction():
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

    const char * getType(){ return "cob_grasp_generation/ShowGraspsAction"; };
    const char * getMD5(){ return "0fdf3be100d1fd874db5cca9ee21a36c"; };

  };

}
#endif