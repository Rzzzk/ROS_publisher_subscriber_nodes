#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>

int main(int argc, char * argv[])
{
    /*Node init*/
    ros::init(argc, argv, "pub_hello_node");
    /*create a hendler*/
    ros::NodeHandle handler;

    /*
        create a publisher/topic
        publisher needs some informations :
            -message type
            -topic name
            -queue size 
    */  
    ros::Publisher pub = handler.advertise<std_msgs::String>("hello_topic", 1000);
    
    /*declear the messge variable*/
    std_msgs::String msg;
    
    ros::Rate loop_rate(10);

    /*asign the message*/
    std::stringstream ss;
    ss << "hello !";
    msg.data = ss.str();

    while(ros::ok())
    {
        /*publish the message*/
        pub.publish(msg);
        ros::spinOnce();
        ROS_INFO("%s", msg.data.c_str());
    }

    return 0;
}
