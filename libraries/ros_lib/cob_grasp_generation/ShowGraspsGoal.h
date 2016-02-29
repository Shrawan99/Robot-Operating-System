#ifndef _ROS_cob_grasp_generation_ShowGraspsGoal_h
#define _ROS_cob_grasp_generation_ShowGraspsGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cob_grasp_generation
{

  class ShowGraspsGoal : public ros::Msg
  {
    public:
      const char* object_name;
      int32_t grasp_id;
      bool sort_by_quality;

    ShowGraspsGoal():
      object_name(""),
      grasp_id(0),
      sort_by_quality(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_object_name = strlen(this->object_name);
      memcpy(outbuffer + offset, &length_object_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->object_name, length_object_name);
      offset += length_object_name;
      union {
        int32_t real;
        uint32_t base;
      } u_grasp_id;
      u_grasp_id.real = this->grasp_id;
      *(outbuffer + offset + 0) = (u_grasp_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_grasp_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_grasp_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_grasp_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->grasp_id);
      union {
        bool real;
        uint8_t base;
      } u_sort_by_quality;
      u_sort_by_quality.real = this->sort_by_quality;
      *(outbuffer + offset + 0) = (u_sort_by_quality.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sort_by_quality);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_object_name;
      memcpy(&length_object_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_object_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_object_name-1]=0;
      this->object_name = (char *)(inbuffer + offset-1);
      offset += length_object_name;
      union {
        int32_t real;
        uint32_t base;
      } u_grasp_id;
      u_grasp_id.base = 0;
      u_grasp_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_grasp_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_grasp_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_grasp_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->grasp_id = u_grasp_id.real;
      offset += sizeof(this->grasp_id);
      union {
        bool real;
        uint8_t base;
      } u_sort_by_quality;
      u_sort_by_quality.base = 0;
      u_sort_by_quality.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->sort_by_quality = u_sort_by_quality.real;
      offset += sizeof(this->sort_by_quality);
     return offset;
    }

    const char * getType(){ return "cob_grasp_generation/ShowGraspsGoal"; };
    const char * getMD5(){ return "7b01b540f64b10e866d31682b977d243"; };

  };

}
#endif