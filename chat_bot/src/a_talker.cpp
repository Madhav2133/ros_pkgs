#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

#define SIZE 500

int main(int argc, char **argv)
{
   ros::init(argc, argv, "a_talker");
   
   ros::NodeHandle n;
   
   ros::Publisher chatter_pub = n.advertise<std_msgs::String>("a_chatter", 1000);
   
   ros::Rate loop_rate(10);
   
   char x[SIZE];
   
   while(ros::ok())
   {
     std_msgs::String msg;
     
     std::stringstream ss;
     
     std::cin.getline(x, SIZE);

     ss << x;
     
     msg.data = ss.str();
     
     //ROS_INFO("%s", msg.data.c_str());
      
     chatter_pub.publish(msg);
     
     ros::spinOnce();
     
     loop_rate.sleep();
   }
   
   return 0;
}