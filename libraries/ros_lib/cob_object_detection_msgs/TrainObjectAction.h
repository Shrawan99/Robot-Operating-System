#ifndef _ROS_cob_object_detection_msgs_TrainObjectAction_h
#define _ROS_cob_object_detection_msgs_TrainObjectAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "cob_object_detection_msgs/TrainObjectActionGoal.h"
#include "cob_object_detection_msgs/TrainObjectActionResult.h"
#include "cob_object_detection_msgs/TrainObjectActionFeedback.h"

namespace cob_object_detection_msgs
{

  class TrainObjectAction : public ros::Msg
  {
    public:
      cob_object_detection_msgs::TrainObjectActionGoal action_goal;
      cob_object_detection_msgs::TrainObjectActionResult action_result;
      cob_object_detection_msgs::TrainObjectActionFeedback action_feedback;

    TrainObjectAction():
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

    const char * getType(){ return "cob_object_detection_msgs/TrainObjectAction"; };
    const char * getMD5(){ return "989cf87235aa440d07ac51414c297bdd"; };

  };

}
#endif