#include <ros/ros.h>
#include <std_msgs/String.h>

void callbackFunc (const std_msgs::String::ConstPtr& msg);

int main(int argc, char **argv)
{
    /*Init node*/
    ros::init(argc, argv, "sub_hello_node");
    /*create a hendler*/
    ros::NodeHandle Handler;

    /*create a subscriber and pass a topic name , message type and callback function
     for handlling the received data*/
    ros::Subscriber sub = Handler.subscribe<std_msgs::String>("hello_topic",1000,callbackFunc);
   
    /*loop*/
    ros::spin();

    return 0;
}

void callbackFunc (const std_msgs::String::ConstPtr& msg)
{
    /*Handle the received message here*/
    ROS_INFO("I heard %s",msg->data.c_str());
}