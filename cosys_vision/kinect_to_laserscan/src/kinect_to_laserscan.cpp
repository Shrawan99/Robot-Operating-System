
#include "pluginlib/class_list_macros.h"
#include "nodelet/nodelet.h"
#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"
#include "sensor_msgs/PointCloud2.h"
#include "pcl/point_cloud.h"
#include "pcl/point_types.h"
#include<pcl/filters/voxel_grid.h>


#include <pcl_ros/transforms.h>
#include <tf/transform_listener.h>
#include <fstream>

// use following header for groovy
//#include<pcl/ros/conversions.h>


// Use following header for hydro
#include<pcl_conversions/pcl_conversions.h>


ros:: Publisher pub;
tf::TransformListener *listener;
tf::StampedTransform transform;

void cloud_cb(const sensor_msgs::PointCloud2ConstPtr& input)
{
    sensor_msgs::PointCloud2 input1;
	 
	pcl::PointCloud<pcl::PointXYZ>::Ptr input_cloud(new pcl::PointCloud<pcl::PointXYZ>);
	
    listener->waitForTransform("/base_footprint", (*input).header.frame_id, (*input).header.stamp, ros::Duration(10.0));
	pcl_ros::transformPointCloud("/base_footprint", *input, input1, *listener);

	//pcl::fromROSMsg (input1, *input_cloud);
	//pcl::VoxelGrid<pcl::PointXYZ> sor;
	//sor.setInputCloud(input_cloud);
	//sor.setLeafSize(0.01,0.01,0.01);
	//sor.filter(*input_cloud);
	//pcl::toROSMsg(*input_cloud,input1);


	sensor_msgs::LaserScanPtr output(new sensor_msgs::LaserScan());
    output->header = input1.header;
    output->header.frame_id ="/base_footprint";
    output->angle_min = -M_PI;
    output->angle_max = M_PI;
    output->angle_increment = M_PI/180.0/2.0;
    output->time_increment = 0.0;
    output->scan_time = 1.0/10.0;
    output->range_min = 0.3;
    output->range_max = 7.0;
    

	
    for (double i = output->angle_min; i <= output->angle_max; i+= output->angle_increment)
    {
      output->ranges.push_back(output->range_max + 1.0);
    }

    pcl::PointCloud<pcl::PointXYZ> cloud;
    pcl::fromROSMsg(input1, cloud);
    for (pcl::PointCloud< pcl::PointXYZ >::const_iterator it = cloud.begin(); it != cloud.end(); ++it)
    {
      const float &x = it->x;
      const float &y = it->y;
      const float &z = it->z;
      // filter out robot's footprint from sensor reading
      //if(z>0.1 && z<2.0 && y>-0.4 && y < 0.4 && x>-0.57 && x<0.65) continue;
      if((y>-0.4 && y < 0.4 && x>-0.57 && x<0.65) || z<0.7 || z >7.0) continue;
      

      double angle = atan2(y,x);
      if (angle < output->angle_min || angle > output->angle_max)
      {
        continue;
      }
      
      int index = (angle - output->angle_min) / output->angle_increment;
      double range_sq = y*y+x*x;
      if (output->ranges[index] * output->ranges[index] > range_sq)
        output->ranges[index] = sqrt(range_sq);
      
    }
    
    
    pub.publish(output);
	}

int main (int argc, char** argv)
{
	ros::init(argc,argv,"kinect_to_laserscan");
	ros::NodeHandle nh;
	listener= new tf::TransformListener();
	ros::Subscriber sub = nh.subscribe("/in_cloud",1, cloud_cb);
	pub = nh.advertise<sensor_msgs::LaserScan>("kinect_laserscan", 1);
    ros::spin();
  
}
