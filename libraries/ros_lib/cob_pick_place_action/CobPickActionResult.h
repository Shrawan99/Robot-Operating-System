#ifndef _ROS_cob_pick_place_action_CobPickActionResult_h
#define _ROS_cob_pick_place_action_CobPickActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "cob_pick_place_action/CobPickResult.h"

namespace cob_pick_place_action
{

  class CobPickActionResult : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalStatus status;
      cob_pick_place_action::CobPickResult result;

    CobPickActionResult():
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

    const char * getType(){ return "cob_pick_place_action/CobPickActionResult"; };
    const char * getMD5(){ return "e1ca3bd5f043f01d499771797966f8a5"; };

  };

}
#endif