#ifndef _ROS_SERVICE_SayText_h
#define _ROS_SERVICE_SayText_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cob_sound
{

static const char SAYTEXT[] = "cob_sound/SayText";

  class SayTextRequest : public ros::Msg
  {
    public:
      const char* text;

    SayTextRequest():
      text("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_text = strlen(this->text);
      memcpy(outbuffer + offset, &length_text, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->text, length_text);
      offset += length_text;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_text;
      memcpy(&length_text, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_text; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_text-1]=0;
      this->text = (char *)(inbuffer + offset-1);
      offset += length_text;
     return offset;
    }

    const char * getType(){ return SAYTEXT; };
    const char * getMD5(){ return "74697ed3d931f6eede8bf3a8dfeca160"; };

  };

  class SayTextResponse : public ros::Msg
  {
    public:

    SayTextResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return SAYTEXT; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SayText {
    public:
    typedef SayTextRequest Request;
    typedef SayTextResponse Response;
  };

}
#endif
