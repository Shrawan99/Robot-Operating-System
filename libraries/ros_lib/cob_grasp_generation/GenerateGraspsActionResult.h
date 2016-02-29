#ifndef _ROS_cob_grasp_generation_GenerateGraspsActionResult_h
#define _ROS_cob_grasp_generation_GenerateGraspsActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "cob_grasp_generation/GenerateGraspsResult.h"

namespace cob_grasp_generation
{

  class GenerateGraspsActionResult : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalStatus status;
      cob_grasp_generation::GenerateGraspsResult result;

    GenerateGraspsActionResult():
      header(),
      status(),
      result()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->result.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->result.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "cob_grasp_generation/GenerateGraspsActionResult"; };
    const char * getMD5(){ return "1f1afbf936d5e62b15a06d30a7d43b0a"; };

  };

}
#endif