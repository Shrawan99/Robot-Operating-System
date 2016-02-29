#ifndef _ROS_cob_grasp_generation_ShowGraspsActionGoal_h
#define _ROS_cob_grasp_generation_ShowGraspsActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "cob_grasp_generation/ShowGraspsGoal.h"

namespace cob_grasp_generation
{

  class ShowGraspsActionGoal : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalID goal_id;
      cob_grasp_generation::ShowGraspsGoal goal;

    ShowGraspsActionGoal():
      header(),
      goal_id(),
      goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->goal_id.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->goal_id.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "cob_grasp_generation/ShowGraspsActionGoal"; };
    const char * getMD5(){ return "68799857835acfead53d4edb4331f62b"; };

  };

}
#endif