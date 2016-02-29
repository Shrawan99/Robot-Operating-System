#ifndef _ROS_SERVICE_GetTOFImages_h
#define _ROS_SERVICE_GetTOFImages_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/Image.h"

namespace cob_camera_sensors
{

static const char GETTOFIMAGES[] = "cob_camera_sensors/GetTOFImages";

  class GetTOFImagesRequest : public ros::Msg
  {
    public:

    GetTOFImagesRequest()
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

    const char * getType(){ return GETTOFIMAGES; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetTOFImagesResponse : public ros::Msg
  {
    public:
      sensor_msgs::Image greyImage;
      sensor_msgs::Image xyzImage;

    GetTOFImagesResponse():
      greyImage(),
      xyzImage()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->greyImage.serialize(outbuffer + offset);
      offset += this->xyzImage.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->greyImage.deserialize(inbuffer + offset);
      offset += this->xyzImage.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETTOFIMAGES; };
    const char * getMD5(){ return "245ce4e6dd0ec61a5c674c8191a91877"; };

  };

  class GetTOFImages {
    public:
    typedef GetTOFImagesRequest Request;
    typedef GetTOFImagesResponse Response;
  };

}
#endif
