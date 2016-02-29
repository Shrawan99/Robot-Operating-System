#ifndef _ROS_cob_grasp_generation_GenerateGraspsActionGoal_h
#define _ROS_cob_grasp_generation_GenerateGraspsActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "cob_grasp_generation/GenerateGraspsGoal.h"

namespace cob_grasp_generation
{

  class GenerateGraspsActionGoal : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalID goal_id;
      cob_grasp_generation::GenerateGraspsGoal goal;

    GenerateGraspsActionGoal():
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

    const char * getType(){ return "cob_grasp_generation/GenerateGraspsActionGoal"; };
    const char * getMD5(){ return "8a208d3f2f382f449c2cd297543dc0dd"; };

  };

}
#endif