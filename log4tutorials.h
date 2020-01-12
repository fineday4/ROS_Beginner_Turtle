
#pragma once

#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
using namespace std;

class Log{
    public:
        Log(const string& filename, const string& path);
        friend void operator<<(Log& log, const string& words);
        ~Log();
    private:
        void info(const string&);
        void warn(const string&);
        void error(const string&);
        static log4cpp::Category& root;
        log4cpp::FileAppender* fileppender;
};

Log::Log(const string& filename, const string& path)
:fileppender(new log4cpp::FileAppender(filename,path+filename))
{
    log4cpp::PatternLayout* pLayout = new log4cpp::PatternLayout();
    pLayout->setConversionPattern("%d: %p %c %x: %m%n");
    log4cpp::FileAppender* fileppender = new log4cpp::FileAppender("fileppender","/home/xuhuanhuan/C++/ROS_Beginner_Turtle/src/testlog4cpp.log");      
    log4cpp::Category& root = log4cpp::Category::getRoot();
    log4cpp::Category& testCategory = root.getInstance("testCategory");
    testCategory.addAppender(fileppender);
    testCategory.setPriority(log4cpp::Priority::INFO);
}

Log::~Log()
{
    log4cpp::Category::shutdown();
}

void Log::info(const string&)
{}

void Log::warn(const string&)
{}

void Log::error(const string&)
{}

log4cpp::Category& Log::root = log4cpp::Category::getRoot();

void operator<<(Log& log, const string& words)
{

}

