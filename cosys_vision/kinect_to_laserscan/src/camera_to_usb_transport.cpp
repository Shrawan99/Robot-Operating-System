
//#include "pluginlib/class_list_macros.h"
#include "nodelet/nodelet.h"
#include "ros/ros.h"
#include "sensor_msgs/CompressedImage.h"
//#include "sensor_msgs/LaserScan.h"
//#include "sensor_msgs/PointCloud2.h"
//#include "pcl/point_cloud.h"
//#include "pcl/point_types.h"
//#include<pcl/filters/voxel_grid.h>


//#include <pcl_ros/transforms.h>
//#include <tf/transform_listener.h>
//#include <fstream>

// use following header for groovy
//#include<pcl/ros/conversions.h>


// Use following header for hydro
//#include<pcl_conversions/pcl_conversions.h>


ros:: Publisher pub1;

void transport_cb(const sensor_msgs::CompressedImage& input)
{
	sensor_msgs::CompressedImage input1;
	input1.header = input.header;
	input1.format  = input.format;
	input1.data = input.data;
	pub1.publish(input1);
}

int main (int argc, char** argv)
{
	ros::init(argc,argv,"camera_to_usb_transport");
	ros::NodeHandle nh;
	ros::Subscriber sub1 = nh.subscribe("/camera/rgb/image_raw/compressed",1,transport_cb);
	pub1 = nh.advertise<sensor_msgs::CompressedImage>("/usb_cam/image_raw/compressed", 1);
    ros::spin();
  
}
