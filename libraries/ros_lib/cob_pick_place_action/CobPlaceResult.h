#ifndef _ROS_cob_pick_place_action_CobPlaceResult_h
#define _ROS_cob_pick_place_action_CobPlaceResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Bool.h"

namespace cob_pick_place_action
{

  class CobPlaceResult : public ros::Msg
  {
    public:
      std_msgs::Bool success;
      const char* cob_pick_error_string;

    CobPlaceResult():
      success(),
      cob_pick_error_string("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->success.serialize(outbuffer + offset);
      uint32_t length_cob_pick_error_string = strlen(this->cob_pick_error_string);
      memcpy(outbuffer + offset, &length_cob_pick_error_string, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->cob_pick_error_string, length_cob_pick_error_string);
      offset += length_cob_pick_error_string;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->success.deserialize(inbuffer + offset);
      uint32_t length_cob_pick_error_string;
      memcpy(&length_cob_pick_error_string, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_cob_pick_error_string; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_cob_pick_error_string-1]=0;
      this->cob_pick_error_string = (char *)(inbuffer + offset-1);
      offset += length_cob_pick_error_string;
     return offset;
    }

    const char * getType(){ return "cob_pick_place_action/CobPlaceResult"; };
    const char * getMD5(){ return "678952546c084eaf4429dc029560eb90"; };

  };

}
#endif