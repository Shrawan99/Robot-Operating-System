#ifndef _ROS_cob_pick_place_action_CobPlaceGoal_h
#define _ROS_cob_pick_place_action_CobPlaceGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"

namespace cob_pick_place_action
{

  class CobPlaceGoal : public ros::Msg
  {
    public:
      uint32_t object_class;
      const char* object_name;
      uint8_t destinations_length;
      geometry_msgs::PoseStamped st_destinations;
      geometry_msgs::PoseStamped * destinations;
      const char* support_surface;

    CobPlaceGoal():
      object_class(0),
      object_name(""),
      destinations_length(0), destinations(NULL),
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
      *(outbuffer + offset++) = destinations_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < destinations_length; i++){
      offset += this->destinations[i].serialize(outbuffer + offset);
      }
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
      uint8_t destinations_lengthT = *(inbuffer + offset++);
      if(destinations_lengthT > destinations_length)
        this->destinations = (geometry_msgs::PoseStamped*)realloc(this->destinations, destinations_lengthT * sizeof(geometry_msgs::PoseStamped));
      offset += 3;
      destinations_length = destinations_lengthT;
      for( uint8_t i = 0; i < destinations_length; i++){
      offset += this->st_destinations.deserialize(inbuffer + offset);
        memcpy( &(this->destinations[i]), &(this->st_destinations), sizeof(geometry_msgs::PoseStamped));
      }
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

    const char * getType(){ return "cob_pick_place_action/CobPlaceGoal"; };
    const char * getMD5(){ return "eac848fa6d0bba67596f88cde36f673b"; };

  };

}
#endif