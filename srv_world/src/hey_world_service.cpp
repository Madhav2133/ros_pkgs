#include"ros/ros.h"
#include"srv_world/hey_world.h"
#include<iostream>
#include<string>

using namespace std;

bool callBack(srv_world::hey_worldRequest& req,srv_world::hey_worldResponse& res)
{
    ROS_INFO("Callback started !");

    string in_name(req.inp);

    if(in_name.compare("Joe")==0)
    {
        res.reply = "How you doin' ?";
    }
    else if(in_name.compare("Pheobe")==0)
    {
        res.reply = "My eyes ! My EYES!!";
    }
    else if(in_name.compare("Ross")==0)
    {
        res.reply = "We were on a break !!";
    }
    else if(in_name.compare("Monica")==0)
    {
        res.reply = "seven, SEVEN";
    }
    else if(in_name.compare("Chandler")==0)
    {
        res.reply = "could you BE any more correct?";
    }
    else if(in_name.compare("Rachel")==0)
    {
        res.reply = "Noooooooooooooo !";
    }
    else
    {
        res.reply = "oops";
    }


    return true;
}


int main(int argc, char** argv)
{
    ros::init(argc,argv,"world_service");

    ros::NodeHandle nh;

    ros::ServiceServer service = nh.advertiseService("Friends",callBack);

    ROS_INFO("Hey !");

    ros::spin();

    return 0;
}