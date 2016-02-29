#ifndef _ROS_cob_grasp_generation_QueryGraspsResult_h
#define _ROS_cob_grasp_generation_QueryGraspsResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/Grasp.h"

namespace cob_grasp_generation
{

  class QueryGraspsResult : public ros::Msg
  {
    public:
      bool success;
      uint8_t grasp_list_length;
      moveit_msgs::Grasp st_grasp_list;
      moveit_msgs::Grasp * grasp_list;

    QueryGraspsResult():
      success(0),
      grasp_list_length(0), grasp_list(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      *(outbuffer + offset++) = grasp_list_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < grasp_list_length; i++){
      offset += this->grasp_list[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
      uint8_t grasp_list_lengthT = *(inbuffer + offset++);
      if(grasp_list_lengthT > grasp_list_length)
        this->grasp_list = (moveit_msgs::Grasp*)realloc(this->grasp_list, grasp_list_lengthT * sizeof(moveit_msgs::Grasp));
      offset += 3;
      grasp_list_length = grasp_list_lengthT;
      for( uint8_t i = 0; i < grasp_list_length; i++){
      offset += this->st_grasp_list.deserialize(inbuffer + offset);
        memcpy( &(this->grasp_list[i]), &(this->st_grasp_list), sizeof(moveit_msgs::Grasp));
      }
     return offset;
    }

    const char * getType(){ return "cob_grasp_generation/QueryGraspsResult"; };
    const char * getMD5(){ return "fda0067ecf92d75eb0f0b5f6c25d3d37"; };

  };

}
#endif