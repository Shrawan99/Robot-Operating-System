#ifndef _ROS_SERVICE_AcquireCalibrationImages_h
#define _ROS_SERVICE_AcquireCalibrationImages_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cob_camera_sensors
{

static const char ACQUIRECALIBRATIONIMAGES[] = "cob_camera_sensors/AcquireCalibrationImages";

  class AcquireCalibrationImagesRequest : public ros::Msg
  {
    public:
      bool reset_image_counter;

    AcquireCalibrationImagesRequest():
      reset_image_counter(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_reset_image_counter;
      u_reset_image_counter.real = this->reset_image_counter;
      *(outbuffer + offset + 0) = (u_reset_image_counter.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->reset_image_counter);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_reset_image_counter;
      u_reset_image_counter.base = 0;
      u_reset_image_counter.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->reset_image_counter = u_reset_image_counter.real;
      offset += sizeof(this->reset_image_counter);
     return offset;
    }

    const char * getType(){ return ACQUIRECALIBRATIONIMAGES; };
    const char * getMD5(){ return "e169cf33c98571b589b34472dd844790"; };

  };

  class AcquireCalibrationImagesResponse : public ros::Msg
  {
    public:

    AcquireCalibrationImagesResponse()
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

    const char * getType(){ return ACQUIRECALIBRATIONIMAGES; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class AcquireCalibrationImages {
    public:
    typedef AcquireCalibrationImagesRequest Request;
    typedef AcquireCalibrationImagesResponse Response;
  };

}
#endif
