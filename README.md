# 如何入手一个项目？
第一步：将这个项目运行起来，知道它做了那些事情；
第二步：建立日志系统，追踪运行过程；
第三步：改进现有项目；
## 文件结构优化：
    将多余内容删除，将有用内容合并相同文件，简化项目内容。
    文件结构说明：
     -> common
     |
     -> roscpp_tutorials: ros学习文件夹，创建目的：边学ROS边做这个项目，这个文件夹就是用来学习用的，turtlesim才是项目的代码存放位置。项目完成的差不多就可以将这个文件删除掉
     |
     -> turtlesim：项目所在位置，这项项目的一期目标是将其改为适用于我的研究方法的仿真实验场所，即：船舶自主导航系统的仿真实验。便于毕业答辩的展示说明。
        |
        -> teleoption：导航控制模块
            |
            -> CMakeLists.txt
            |
            -> draw_square.cpp
            |
            -> mimic.cpp
            |
            -> package.xml
            |
            -> teleop_turtle_key.cpp
        |
        -> turtlesim：船舶执行模块
            |
            -> images
            |
            -> include
            |
            -> launch
            |
            -> msg
            |
            -> src
                |
                -> turtlesim
                    |
                    -> __init__.py
                |
                -> turtle_frame.cpp
                |
                -> turtle.cpp
                |
                -> turtlesim.cpp
            |
            -> srv
            |
            -> CHANGEL.rst
            |
            -> CMakeLists.txt
            |
            -> package.xml
     |
     -> CMakeLists.txt
## 第二步：建立日志系统：
 ### 2.1 log4cpp从安装到运行成功
     去官网下载log4cpp.tar.gz；
     解压后运行： ./configure -> make -> make check -> sudo make install
     连接log4cpp.so文件：export LD_LIBRARY_PATH=/usr/local/lib/
     编译：g++ testlog4cpp.cc -std=c++11 -llog4cpp -lpthread -o testlog4cpp
     运行testlog4cpp即可。
 ### 2.2 log4cpp日志系统的建立(三天)
    第一天：构思-》log4tutorials.h