#ifndef TURTLESIM_TURTLE_H
#define TURTLESIM_TURTLE_H

// This prevents a MOC error with versions of boost >= 1.48
#ifndef Q_MOC_RUN  // See: https://bugreports.qt-project.org/browse/QTBUG-22829
# include <ros/ros.h>
# include <boost/shared_ptr.hpp>
# include <geometry_msgs/Twist.h>

//turtlesim/*是在哪里找到的？？
# include <turtlesim/Pose.h>
# include <turtlesim/SetPen.h>
# include <turtlesim/TeleportRelative.h>
# include <turtlesim/TeleportAbsolute.h>
# include <turtlesim/Color.h>
#endif

#include <QImage>
#include <QPainter>
#include <QPen>
#include <QPointF>

#define PI 3.14159265

namespace turtlesim
{

class Turtle
{
public:
  Turtle(const ros::NodeHandle& nh, const QImage& turtle_image, const QPointF& pos, float orient);

//更新图片
  bool update(double dt, QPainter& path_painter, const QImage& path_image, qreal canvas_width, qreal canvas_height);
//绘制图片
  void paint(QPainter &painter);
private:
//设置各阶段的回调函数
  void velocityCallback(const geometry_msgs::Twist::ConstPtr& vel);//速度回调函数
  bool setPenCallback(turtlesim::SetPen::Request&, turtlesim::SetPen::Response&);//绘图
  bool teleportRelativeCallback(turtlesim::TeleportRelative::Request&, turtlesim::TeleportRelative::Response&);//
  bool teleportAbsoluteCallback(turtlesim::TeleportAbsolute::Request&, turtlesim::TeleportAbsolute::Response&);
//图片的旋转
  void rotateImage();

  ros::NodeHandle nh_;

  QImage turtle_image_;
  QImage turtle_rotated_image_;

  QPointF pos_;
  qreal orient_;

  qreal lin_vel_;
  qreal ang_vel_;
  bool pen_on_;
  QPen pen_;

  ros::Subscriber velocity_sub_;
  ros::Publisher pose_pub_;
  ros::Publisher color_pub_;
  ros::ServiceServer set_pen_srv_;
  ros::ServiceServer teleport_relative_srv_;
  ros::ServiceServer teleport_absolute_srv_;

  ros::WallTime last_command_time_;

  float meter_;
//按键请求的存储结构
  struct TeleportRequest
  {
    TeleportRequest(float x, float y, qreal _theta, qreal _linear, bool _relative)
    : pos(x, y)
    , theta(_theta)
    , linear(_linear)
    , relative(_relative)
    {}

    QPointF pos;
    qreal theta;
    qreal linear;
    bool relative;
  };
  typedef std::vector<TeleportRequest> V_TeleportRequest;
  V_TeleportRequest teleport_requests_;
};
typedef boost::shared_ptr<Turtle> TurtlePtr;

}

#endif
