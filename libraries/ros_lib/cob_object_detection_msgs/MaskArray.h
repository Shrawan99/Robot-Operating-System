#ifndef _ROS_cob_object_detection_msgs_MaskArray_h
#define _ROS_cob_object_detection_msgs_MaskArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "cob_object_detection_msgs/Mask.h"

namespace cob_object_detection_msgs
{

  class MaskArray : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t masks_length;
      cob_object_detection_msgs::Mask st_masks;
      cob_object_detection_msgs::Mask * masks;

    MaskArray():
      header(),
      masks_length(0), masks(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = masks_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < masks_length; i++){
      offset += this->masks[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t masks_lengthT = *(inbuffer + offset++);
      if(masks_lengthT > masks_length)
        this->masks = (cob_object_detection_msgs::Mask*)realloc(this->masks, masks_lengthT * sizeof(cob_object_detection_msgs::Mask));
      offset += 3;
      masks_length = masks_lengthT;
      for( uint8_t i = 0; i < masks_length; i++){
      offset += this->st_masks.deserialize(inbuffer + offset);
        memcpy( &(this->masks[i]), &(this->st_masks), sizeof(cob_object_detection_msgs::Mask));
      }
     return offset;
    }

    const char * getType(){ return "cob_object_detection_msgs/MaskArray"; };
    const char * getMD5(){ return "1d4620a4218f096b919a95d7fb64146f"; };

  };

}
#endif