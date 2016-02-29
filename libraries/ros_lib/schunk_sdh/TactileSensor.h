#ifndef _ROS_schunk_sdh_TactileSensor_h
#define _ROS_schunk_sdh_TactileSensor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "schunk_sdh/TactileMatrix.h"

namespace schunk_sdh
{

  class TactileSensor : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t tactile_matrix_length;
      schunk_sdh::TactileMatrix st_tactile_matrix;
      schunk_sdh::TactileMatrix * tactile_matrix;

    TactileSensor():
      header(),
      tactile_matrix_length(0), tactile_matrix(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = tactile_matrix_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < tactile_matrix_length; i++){
      offset += this->tactile_matrix[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t tactile_matrix_lengthT = *(inbuffer + offset++);
      if(tactile_matrix_lengthT > tactile_matrix_length)
        this->tactile_matrix = (schunk_sdh::TactileMatrix*)realloc(this->tactile_matrix, tactile_matrix_lengthT * sizeof(schunk_sdh::TactileMatrix));
      offset += 3;
      tactile_matrix_length = tactile_matrix_lengthT;
      for( uint8_t i = 0; i < tactile_matrix_length; i++){
      offset += this->st_tactile_matrix.deserialize(inbuffer + offset);
        memcpy( &(this->tactile_matrix[i]), &(this->st_tactile_matrix), sizeof(schunk_sdh::TactileMatrix));
      }
     return offset;
    }

    const char * getType(){ return "schunk_sdh/TactileSensor"; };
    const char * getMD5(){ return "c6176a03c00cccf1b8efd3037de0d45d"; };

  };

}
#endif