#ifndef _ROS_schunk_sdh_TactileMatrix_h
#define _ROS_schunk_sdh_TactileMatrix_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace schunk_sdh
{

  class TactileMatrix : public ros::Msg
  {
    public:
      uint32_t matrix_id;
      int16_t cells_x;
      int16_t cells_y;
      uint8_t tactile_array_length;
      int16_t st_tactile_array;
      int16_t * tactile_array;

    TactileMatrix():
      matrix_id(0),
      cells_x(0),
      cells_y(0),
      tactile_array_length(0), tactile_array(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->matrix_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->matrix_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->matrix_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->matrix_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->matrix_id);
      union {
        int16_t real;
        uint16_t base;
      } u_cells_x;
      u_cells_x.real = this->cells_x;
      *(outbuffer + offset + 0) = (u_cells_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cells_x.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->cells_x);
      union {
        int16_t real;
        uint16_t base;
      } u_cells_y;
      u_cells_y.real = this->cells_y;
      *(outbuffer + offset + 0) = (u_cells_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cells_y.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->cells_y);
      *(outbuffer + offset++) = tactile_array_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < tactile_array_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_tactile_arrayi;
      u_tactile_arrayi.real = this->tactile_array[i];
      *(outbuffer + offset + 0) = (u_tactile_arrayi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tactile_arrayi.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->tactile_array[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->matrix_id =  ((uint32_t) (*(inbuffer + offset)));
      this->matrix_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->matrix_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->matrix_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->matrix_id);
      union {
        int16_t real;
        uint16_t base;
      } u_cells_x;
      u_cells_x.base = 0;
      u_cells_x.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cells_x.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->cells_x = u_cells_x.real;
      offset += sizeof(this->cells_x);
      union {
        int16_t real;
        uint16_t base;
      } u_cells_y;
      u_cells_y.base = 0;
      u_cells_y.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cells_y.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->cells_y = u_cells_y.real;
      offset += sizeof(this->cells_y);
      uint8_t tactile_array_lengthT = *(inbuffer + offset++);
      if(tactile_array_lengthT > tactile_array_length)
        this->tactile_array = (int16_t*)realloc(this->tactile_array, tactile_array_lengthT * sizeof(int16_t));
      offset += 3;
      tactile_array_length = tactile_array_lengthT;
      for( uint8_t i = 0; i < tactile_array_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_st_tactile_array;
      u_st_tactile_array.base = 0;
      u_st_tactile_array.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_tactile_array.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_tactile_array = u_st_tactile_array.real;
      offset += sizeof(this->st_tactile_array);
        memcpy( &(this->tactile_array[i]), &(this->st_tactile_array), sizeof(int16_t));
      }
     return offset;
    }

    const char * getType(){ return "schunk_sdh/TactileMatrix"; };
    const char * getMD5(){ return "ab718b6c1d4d719110707994d2e325e4"; };

  };

}
#endif