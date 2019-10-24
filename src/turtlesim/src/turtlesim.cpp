#include <QApplication>  //可能是QT组件

#include <ros/ros.h>

#include "turtlesim/turtle_frame.h"

class TurtleApp : public QApplication
{
public:
  ros::NodeHandlePtr nh_;

  TurtleApp(int& argc, char** argv)
    : QApplication(argc, argv)
  {
    ros::init(argc, argv, "turtlesim_test", ros::init_options::NoSigintHandler);
    nh_.reset(new ros::NodeHandle);
  }

  int exec()
  {
    turtlesim::TurtleFrame frame;
    frame.show();//show应该是TurtleFrame的父类QFrame实现的方法

    return QApplication::exec();
  }
};

int main(int argc, char** argv)
{
  TurtleApp app(argc, argv);
  return app.exec();
}

