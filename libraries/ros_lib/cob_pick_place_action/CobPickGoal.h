#ifndef _ROS_cob_pick_place_action_CobPickGoal_h
#define _ROS_cob_pick_place_action_CobPickGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"

namespace cob_pick_place_action
{

  class CobPickGoal : public ros::Msg
  {
    public:
      uint32_t object_class;
      const char* object_name;
      geometry_msgs::PoseStamped object_pose;
      const char* grasp_database;
      uint32_t grasp_id;
      const char* support_surface;

    CobPickGoal():
      object_class(0),
      object_name(""),
      object_pose(),
      grasp_database(""),
      grasp_id(0),
      support_surface("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->object_class >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->object_class >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->object_class >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->object_class >> (8 * 3)) & 0xFF;
      offset += sizeof(this->object_class);
      uint32_t length_object_name = strlen(this->object_name);
      memcpy(outbuffer + offset, &length_object_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->object_name, length_object_name);
      offset += length_object_name;
      offset += this->object_pose.serialize(outbuffer + offset);
      uint32_t length_grasp_database = strlen(this->grasp_database);
      memcpy(outbuffer + offset, &length_grasp_database, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->grasp_database, length_grasp_database);
      offset += length_grasp_database;
      *(outbuffer + offset + 0) = (this->grasp_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->grasp_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->grasp_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->grasp_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->grasp_id);
      uint32_t length_support_surface = strlen(this->support_surface);
      memcpy(outbuffer + offset, &length_support_surface, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->support_surface, length_support_surface);
      offset += length_support_surface;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->object_class =  ((uint32_t) (*(inbuffer + offset)));
      this->object_class |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->object_class |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->object_class |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->object_class);
      uint32_t length_object_name;
      memcpy(&length_object_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_object_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_object_name-1]=0;
      this->object_name = (char *)(inbuffer + offset-1);
      offset += length_object_name;
      offset += this->object_pose.deserialize(inbuffer + offset);
      uint32_t length_grasp_database;
      memcpy(&length_grasp_database, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_grasp_database; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_grasp_database-1]=0;
      this->grasp_database = (char *)(inbuffer + offset-1);
      offset += length_grasp_database;
      this->grasp_id =  ((uint32_t) (*(inbuffer + offset)));
      this->grasp_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->grasp_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->grasp_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->grasp_id);
      uint32_t length_support_surface;
      memcpy(&length_support_surface, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_support_surface; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_support_surface-1]=0;
      this->support_surface = (char *)(inbuffer + offset-1);
      offset += length_support_surface;
     return offset;
    }

    const char * getType(){ return "cob_pick_place_action/CobPickGoal"; };
    const char * getMD5(){ return "98c44a3be849194f7362e5ea42420c0e"; };

  };

}
#endif