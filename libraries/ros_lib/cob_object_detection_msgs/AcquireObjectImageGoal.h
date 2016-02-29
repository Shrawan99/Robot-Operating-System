#ifndef _ROS_cob_object_detection_msgs_AcquireObjectImageGoal_h
#define _ROS_cob_object_detection_msgs_AcquireObjectImageGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"

namespace cob_object_detection_msgs
{

  class AcquireObjectImageGoal : public ros::Msg
  {
    public:
      const char* object_name;
      bool reset_image_counter;
      geometry_msgs::PoseStamped pose;
      uint8_t sdh_joints_length;
      geometry_msgs::PoseStamped st_sdh_joints;
      geometry_msgs::PoseStamped * sdh_joints;

    AcquireObjectImageGoal():
      object_name(""),
      reset_image_counter(0),
      pose(),
      sdh_joints_length(0), sdh_joints(NULL)
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
      } u_reset_image_counter;
      u_reset_image_counter.real = this->reset_image_counter;
      *(outbuffer + offset + 0) = (u_reset_image_counter.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->reset_image_counter);
      offset += this->pose.serialize(outbuffer + offset);
      *(outbuffer + offset++) = sdh_joints_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < sdh_joints_length; i++){
      offset += this->sdh_joints[i].serialize(outbuffer + offset);
      }
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
      } u_reset_image_counter;
      u_reset_image_counter.base = 0;
      u_reset_image_counter.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->reset_image_counter = u_reset_image_counter.real;
      offset += sizeof(this->reset_image_counter);
      offset += this->pose.deserialize(inbuffer + offset);
      uint8_t sdh_joints_lengthT = *(inbuffer + offset++);
      if(sdh_joints_lengthT > sdh_joints_length)
        this->sdh_joints = (geometry_msgs::PoseStamped*)realloc(this->sdh_joints, sdh_joints_lengthT * sizeof(geometry_msgs::PoseStamped));
      offset += 3;
      sdh_joints_length = sdh_joints_lengthT;
      for( uint8_t i = 0; i < sdh_joints_length; i++){
      offset += this->st_sdh_joints.deserialize(inbuffer + offset);
        memcpy( &(this->sdh_joints[i]), &(this->st_sdh_joints), sizeof(geometry_msgs::PoseStamped));
      }
     return offset;
    }

    const char * getType(){ return "cob_object_detection_msgs/AcquireObjectImageGoal"; };
    const char * getMD5(){ return "a834da64b488488418ecf10d2737befd"; };

  };

}
#endif