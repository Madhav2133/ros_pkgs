#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char** argv)
{
    ros::init(argc,argv,"talker");

    ros::NodeHandle nh;

    ros::Publisher topic_pub = nh.advertise<std_msgs::String>("Hello_World",1000);

    ros::Rate loop_rate(3);

    while(ros::ok())
    {
        std_msgs::String msg;

        msg.data = "Hello World !";

        topic_pub.publish(msg);

        ros::spinOnce();

        loop_rate.sleep();
    }

    return 0;
}