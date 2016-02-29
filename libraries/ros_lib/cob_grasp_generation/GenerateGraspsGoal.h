#ifndef _ROS_cob_grasp_generation_GenerateGraspsGoal_h
#define _ROS_cob_grasp_generation_GenerateGraspsGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cob_grasp_generation
{

  class GenerateGraspsGoal : public ros::Msg
  {
    public:
      const char* object_name;
      bool replan;
      bool viewer;

    GenerateGraspsGoal():
      object_name(""),
      replan(0),
      viewer(0)
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
        bool real;
        uint8_t base;
      } u_replan;
      u_replan.real = this->replan;
      *(outbuffer + offset + 0) = (u_replan.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->replan);
      union {
        bool real;
        uint8_t base;
      } u_viewer;
      u_viewer.real = this->viewer;
      *(outbuffer + offset + 0) = (u_viewer.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->viewer);
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
        bool real;
        uint8_t base;
      } u_replan;
      u_replan.base = 0;
      u_replan.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->replan = u_replan.real;
      offset += sizeof(this->replan);
      union {
        bool real;
        uint8_t base;
      } u_viewer;
      u_viewer.base = 0;
      u_viewer.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->viewer = u_viewer.real;
      offset += sizeof(this->viewer);
     return offset;
    }

    const char * getType(){ return "cob_grasp_generation/GenerateGraspsGoal"; };
    const char * getMD5(){ return "da156e2bc9bf3f3c3e0ea870759aca05"; };

  };

}
#endif