#include"ros/ros.h"
#include"srv_world/hey_world.h"
#include<iostream>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
    ros::init(argc,argv,"world_client");

    ros::NodeHandle nh;

    ros::ServiceClient client = nh.serviceClient<srv_world::hey_world>("Friends");

    srv_world::hey_world f;

    string input;

    while(ros::ok())
    {
        cout << endl;

        cout << "Input (q to quit) :";

        cin >> input;

        if(input.compare("q")==0)
            return 0;

        f.request.inp = input;

        if(client.call(f))
        {
            cout << f.request.inp << " dailogue : " << f.response.reply <<endl;
        }
        else
        {
            ROS_ERROR("Unable to call the server ! ");
        }

        return 1;

    }

    return 0;
}