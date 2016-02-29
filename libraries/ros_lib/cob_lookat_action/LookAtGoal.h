#ifndef _ROS_cob_lookat_action_LookAtGoal_h
#define _ROS_cob_lookat_action_LookAtGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"

namespace cob_lookat_action
{

  class LookAtGoal : public ros::Msg
  {
    public:
      geometry_msgs::PoseStamped target;

    LookAtGoal():
      target()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->target.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->target.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "cob_lookat_action/LookAtGoal"; };
    const char * getMD5(){ return "8ba8aeef25187f3dc987f3a87f890b3a"; };

  };

}
#endif