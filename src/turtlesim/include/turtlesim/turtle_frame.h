#include <QFrame>
#include <QImage>
#include <QPainter>
#include <QPaintEvent>
#include <QTimer>
#include <QVector>

// This prevents a MOC error with versions of boost >= 1.48
#ifndef Q_MOC_RUN  // See: https://bugreports.qt-project.org/browse/QTBUG-22829
# include <ros/ros.h>

# include <std_srvs/Empty.h>
# include <turtlesim/Spawn.h>
# include <turtlesim/Kill.h>
# include <map>

# include "turtle.h"
#endif

namespace turtlesim
{
  //TurtleFrame的作用就是处理turtle在窗口中的展示

class TurtleFrame : public QFrame
{
  Q_OBJECT
public:
  TurtleFrame(QWidget* parent = 0, Qt::WindowFlags f = 0);
  ~TurtleFrame();

  //在窗口中设置乌龟的位置和姿态
  std::string spawnTurtle(const std::string& name, float x, float y, float angle);
  std::string spawnTurtle(const std::string& name, float x, float y, float angle, size_t index);

protected:
//绘图事件
  void paintEvent(QPaintEvent* event);

private slots:
  void onUpdate();

private:
  void updateTurtles();
  void clear();
  bool hasTurtle(const std::string& name);

  bool clearCallback(std_srvs::Empty::Request&, std_srvs::Empty::Response&);
  bool resetCallback(std_srvs::Empty::Request&, std_srvs::Empty::Response&);
  bool spawnCallback(turtlesim::Spawn::Request&, turtlesim::Spawn::Response&);
  bool killCallback(turtlesim::Kill::Request&, turtlesim::Kill::Response&);
//如何理解NodeHandle：这是用来操作ROS方法的句柄，用来操作suberscribe,publish,adverise等等
  ros::NodeHandle nh_;
  QTimer* update_timer_;
  QImage path_image_;
  QPainter path_painter_;

  uint64_t frame_count_;

  ros::WallTime last_turtle_update_;

  ros::ServiceServer clear_srv_;//清空服务
  ros::ServiceServer reset_srv_;//重置
  ros::ServiceServer spawn_srv_;//
  ros::ServiceServer kill_srv_;//杀死

  typedef std::map<std::string, TurtlePtr> M_Turtle;
  M_Turtle turtles_;
  uint32_t id_counter_;

  QVector<QImage> turtle_images_;

  float meter_;
  float width_in_meters_;
  float height_in_meters_;
};

}
