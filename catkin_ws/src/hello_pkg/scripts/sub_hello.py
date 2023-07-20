#! /usr/bin/env python3

from std_msgs.msg import String
import rospy


def main():
    #initialze ros node
    rospy.init_node('sub_hello_node2') 

    #create Subscribe to sub a topic 
    #       topic name   : topic1 
    #       message type : String
    rospy.Subscriber('topic1' , String , callback)
    
    #loop  
    rospy.spin()
    
    
#callback function to handle th ereceived message    
def callback(msg):
    #just to handle the data
    rospy.loginfo("I received %s" % msg.data)  # = print(" --- ")
    
if __name__ == '__main__' :
        main()
