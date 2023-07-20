#! /usr/bin/env python3

import rospy
from std_msgs.msg import String

def main():
    #initialze ros node
    rospy.init_node('pub_hello_node2') 

    #initialize ros publisher/topic
    pub = rospy.Publisher('topic1' , String , queue_size=10 )

    #initialize ros rate
    rate = rospy.Rate(10)
    #while user not exit from the program
    while not rospy.is_shutdown():
        #creating msg
        hello_str = "hello world!"
        #punlish msg to topic
        pub.publish(hello_str)
        #sleep for a time
        rate.sleep()


if __name__ == '__main__' :
    try:
        main()
    except rospy.ROSInterruptException:
        pass