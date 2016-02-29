#ifndef _ROS_cob_grasp_generation_QueryGraspsActionResult_h
#define _ROS_cob_grasp_generation_QueryGraspsActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "cob_grasp_generation/QueryGraspsResult.h"

namespace cob_grasp_generation
{

  class QueryGraspsActionResult : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalStatus status;
      cob_grasp_generation::QueryGraspsResult result;

    QueryGraspsActionResult():
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

    const char * getType(){ return "cob_grasp_generation/QueryGraspsActionResult"; };
    const char * getMD5(){ return "c30242ade55071edc674133f494da278"; };

  };

}
#endif