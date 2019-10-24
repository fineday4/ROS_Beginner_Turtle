#include <ros/ros.h>
#include "beginner_tutorials/AddTwoInts.h"

//service服务端的回调函数
bool
add(beginner_tutorials::AddTwoInts::Request &req,beginner_tutorials::AddTwoInts::Response &res)
{
 res.sum = req.a + req.b;
 ROS_INFO("request: x=%ld, y=%ld",(long int)req.a,(long int)req.b);
 ROS_INFO("sending back response: [%ld]",(long int)res.sum);

return true;
}

int
main(int argc, char **argv)
{
 ros::init(argc,argv,"add_two_ints_server");
 ros::NodeHandle n;
 ros::ServiceServer service = n.advertiseService("add_two_ints",add);//advertiseService返回一个名为add_two_ints注册的回调函数为add的
 //service
 ROS_INFO("Ready to add two ints.");
// ros::spinonce();
 ros::spin();//在这里阻塞监听client端是否可读，如果可读就会执行之前注册的回调函数

 return 0;
}
