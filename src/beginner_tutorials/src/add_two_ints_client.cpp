//service通信客户端
#include <ros/ros.h>
#include "beginner_tutorials/AddTwoInts.h"//没有AddTwoInts.h？？？
#include <cstdlib>

int
main(int argc, char **argv)
{
ros::init(argc,argv,"add_two_ints_client");//ros初始化
 if(argc != 3)
 {
  ROS_INFO("usage:add_two_ints_client X Y");　　//ROS日志
  return 1;
 }
 ros::NodeHandle n;　　　　　　　　　　//创建ros句柄
 ros::ServiceClient client = n.serviceClient<beginner_tutorials::AddTwoInts>("add_two_ints");
 //返回一个通讯格式为beginner_tutorials文件下的AddTwoInts.srv规定名为add_two_ints的service客户端
 beginner_tutorials::AddTwoInts srv;
 srv.request.a = atoll(argv[1]);
 srv.request.b = atoll(argv[2]);
 if(client.call(srv))//call与service通讯结果在srv的response中保存．
 {
  ROS_INFO("Sum: %ld",(long int)srv.response.sum);
 }else{
  ROS_ERROR("Failed to call service add_two_ints");
  return 1;
 }

 return 0;
}
