#ifndef _ROS_cob_script_server_StateAction_h
#define _ROS_cob_script_server_StateAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "cob_script_server/StateActionGoal.h"
#include "cob_script_server/StateActionResult.h"
#include "cob_script_server/StateActionFeedback.h"

namespace cob_script_server
{

  class StateAction : public ros::Msg
  {
    public:
      cob_script_server::StateActionGoal action_goal;
      cob_script_server::StateActionResult action_result;
      cob_script_server::StateActionFeedback action_feedback;

    StateAction():
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

    const char * getType(){ return "cob_script_server/StateAction"; };
    const char * getMD5(){ return "8053233aa3e0dd581f127cd6e23e3f9a"; };

  };

}
#endif