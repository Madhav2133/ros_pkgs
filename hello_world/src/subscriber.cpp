#include "ros/ros.h"
#include "std_msgs/String.h"

void callBack(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("He said : %s",msg->data.c_str());
}

int main(int argc, char** argv)
{
   ros::init(argc,argv,"subscriber");

   ros::NodeHandle nh;

   ros::Subscriber topic_sub = nh.subscribe("Hello_World",1000,callBack);

   ros::spin();

   return 0;   
}