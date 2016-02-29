#ifndef _ROS_cob_phidgets_DigitalSensor_h
#define _ROS_cob_phidgets_DigitalSensor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cob_phidgets
{

  class DigitalSensor : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t uri_length;
      char* st_uri;
      char* * uri;
      uint8_t state_length;
      int8_t st_state;
      int8_t * state;

    DigitalSensor():
      header(),
      uri_length(0), uri(NULL),
      state_length(0), state(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = uri_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < uri_length; i++){
      uint32_t length_urii = strlen(this->uri[i]);
      memcpy(outbuffer + offset, &length_urii, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->uri[i], length_urii);
      offset += length_urii;
      }
      *(outbuffer + offset++) = state_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < state_length; i++){
      union {
        int8_t real;
        uint8_t base;
      } u_statei;
      u_statei.real = this->state[i];
      *(outbuffer + offset + 0) = (u_statei.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->state[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t uri_lengthT = *(inbuffer + offset++);
      if(uri_lengthT > uri_length)
        this->uri = (char**)realloc(this->uri, uri_lengthT * sizeof(char*));
      offset += 3;
      uri_length = uri_lengthT;
      for( uint8_t i = 0; i < uri_length; i++){
      uint32_t length_st_uri;
      memcpy(&length_st_uri, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_uri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_uri-1]=0;
      this->st_uri = (char *)(inbuffer + offset-1);
      offset += length_st_uri;
        memcpy( &(this->uri[i]), &(this->st_uri), sizeof(char*));
      }
      uint8_t state_lengthT = *(inbuffer + offset++);
      if(state_lengthT > state_length)
        this->state = (int8_t*)realloc(this->state, state_lengthT * sizeof(int8_t));
      offset += 3;
      state_length = state_lengthT;
      for( uint8_t i = 0; i < state_length; i++){
      union {
        int8_t real;
        uint8_t base;
      } u_st_state;
      u_st_state.base = 0;
      u_st_state.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_state = u_st_state.real;
      offset += sizeof(this->st_state);
        memcpy( &(this->state[i]), &(this->st_state), sizeof(int8_t));
      }
     return offset;
    }

    const char * getType(){ return "cob_phidgets/DigitalSensor"; };
    const char * getMD5(){ return "a7555c23666cea5795a76c1bdec02d2c"; };

  };

}
#endif