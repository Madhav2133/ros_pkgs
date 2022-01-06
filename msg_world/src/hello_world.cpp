#include "ros/ros.h"
#include "msg_world/hello_world.h"

int main(int argc, char** argv)
{
    ros::init(argc,argv,"announce");

    ros::NodeHandle nh;

    ros::Publisher topic_publisher = nh.advertise<msg_world::hello_world>("Msg_To_World",1000);

    msg_world::hello_world my_msg;

    ros::Rate loop_rate(3);

    my_msg.header.stamp = ros::Time::now();

    my_msg.header.seq = 0;

    my_msg.header.frame_id = "Hello World !";

    my_msg.dm = "! Dlrow Olleh";

    while(ros::ok())
    {
        my_msg.header.seq++;

        my_msg.header.stamp = ros::Time::now();

        topic_publisher.publish(my_msg);

        ros::spinOnce();

        loop_rate.sleep();
    }

    return 0;
}