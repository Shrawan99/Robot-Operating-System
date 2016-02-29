#ifndef _ROS_cob_phidgets_AnalogSensor_h
#define _ROS_cob_phidgets_AnalogSensor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cob_phidgets
{

  class AnalogSensor : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t uri_length;
      char* st_uri;
      char* * uri;
      uint8_t value_length;
      int16_t st_value;
      int16_t * value;

    AnalogSensor():
      header(),
      uri_length(0), uri(NULL),
      value_length(0), value(NULL)
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
      *(outbuffer + offset++) = value_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < value_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_valuei;
      u_valuei.real = this->value[i];
      *(outbuffer + offset + 0) = (u_valuei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_valuei.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->value[i]);
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
      uint8_t value_lengthT = *(inbuffer + offset++);
      if(value_lengthT > value_length)
        this->value = (int16_t*)realloc(this->value, value_lengthT * sizeof(int16_t));
      offset += 3;
      value_length = value_lengthT;
      for( uint8_t i = 0; i < value_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_st_value;
      u_st_value.base = 0;
      u_st_value.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_value.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_value = u_st_value.real;
      offset += sizeof(this->st_value);
        memcpy( &(this->value[i]), &(this->st_value), sizeof(int16_t));
      }
     return offset;
    }

    const char * getType(){ return "cob_phidgets/AnalogSensor"; };
    const char * getMD5(){ return "b52a946d34a1d251ef4461cdadfa70ae"; };

  };

}
#endif