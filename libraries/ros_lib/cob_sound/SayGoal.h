#ifndef _ROS_cob_sound_SayGoal_h
#define _ROS_cob_sound_SayGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/String.h"

namespace cob_sound
{

  class SayGoal : public ros::Msg
  {
    public:
      std_msgs::String text;

    SayGoal():
      text()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->text.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->text.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "cob_sound/SayGoal"; };
    const char * getMD5(){ return "7fb91077b93c329c9eeaea1c488c03e0"; };

  };

}
#endif