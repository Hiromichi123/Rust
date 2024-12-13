//该例程将订阅/person_info话题，自定义消息类型learning_topic::Person
#include<ros/ros.h>
#include"learning_topic/Person.h"

//回调函数
void personInfoCallback(const learning_topic::Person::ConstPtr& msg)
{
    ROS_INFO("Subscribe Person Info:name:%s age:%d sex:%d",
              msg->name.c_str(),msg->age,msg->sex);
}

int main(int argc,char**argv)
{
    ros::init(argc,argv,"person_subscriber");
    ros::NodeHandle n;

    ros::Subscriber person_info_pub=n.subscribe("/person_info",10,personInfoCallback);

    ros::spin();

    return 0;
}