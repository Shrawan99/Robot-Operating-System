#ifndef _ROS_cob_light_LightMode_h
#define _ROS_cob_light_LightMode_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/ColorRGBA.h"

namespace cob_light
{

  class LightMode : public ros::Msg
  {
    public:
      uint8_t mode;
      std_msgs::ColorRGBA color;
      float frequency;
      float timeout;
      int32_t pulses;
      int8_t priority;
      enum { NONE =  0 			 };
      enum { STATIC =  1 		 };
      enum { FLASH =  2 		 };
      enum { BREATH =  3 		 };
      enum { BREATH_COLOR =  4 	 };
      enum { FADE_COLOR =  5 	 };

    LightMode():
      mode(0),
      color(),
      frequency(0),
      timeout(0),
      pulses(0),
      priority(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mode);
      offset += this->color.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_frequency;
      u_frequency.real = this->frequency;
      *(outbuffer + offset + 0) = (u_frequency.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_frequency.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_frequency.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_frequency.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->frequency);
      union {
        float real;
        uint32_t base;
      } u_timeout;
      u_timeout.real = this->timeout;
      *(outbuffer + offset + 0) = (u_timeout.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_timeout.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_timeout.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_timeout.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timeout);
      union {
        int32_t real;
        uint32_t base;
      } u_pulses;
      u_pulses.real = this->pulses;
      *(outbuffer + offset + 0) = (u_pulses.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pulses.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pulses.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pulses.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pulses);
      union {
        int8_t real;
        uint8_t base;
      } u_priority;
      u_priority.real = this->priority;
      *(outbuffer + offset + 0) = (u_priority.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->priority);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->mode);
      offset += this->color.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_frequency;
      u_frequency.base = 0;
      u_frequency.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_frequency.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_frequency.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_frequency.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->frequency = u_frequency.real;
      offset += sizeof(this->frequency);
      union {
        float real;
        uint32_t base;
      } u_timeout;
      u_timeout.base = 0;
      u_timeout.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_timeout.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_timeout.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_timeout.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->timeout = u_timeout.real;
      offset += sizeof(this->timeout);
      union {
        int32_t real;
        uint32_t base;
      } u_pulses;
      u_pulses.base = 0;
      u_pulses.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pulses.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pulses.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pulses.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pulses = u_pulses.real;
      offset += sizeof(this->pulses);
      union {
        int8_t real;
        uint8_t base;
      } u_priority;
      u_priority.base = 0;
      u_priority.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->priority = u_priority.real;
      offset += sizeof(this->priority);
     return offset;
    }

    const char * getType(){ return "cob_light/LightMode"; };
    const char * getMD5(){ return "5c61cdd41b56356f16e4e7ab38a77236"; };

  };

}
#endif