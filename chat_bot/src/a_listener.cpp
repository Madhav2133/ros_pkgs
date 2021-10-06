#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
   ROS_INFO("B said: %s", msg->data.c_str());
}

int main(int argc, char **argv)
{
   
   ros::init(argc, argv, "a_listener");
   
   ros::NodeHandle n;
   
   ros::Subscriber sub = n.subscribe("b_chatter", 1000, chatterCallback);
   
   ros::spin();
   
   return 0;
}