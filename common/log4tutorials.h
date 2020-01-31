
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
      //  friend void operator<<(Log& log, const string& words);
        ~Log();
    private:
        void info(const string&);
        void warn(const string&);
        void error(const string&);
        static log4cpp::Category& root;
        log4cpp::FileAppender* fileppender;
        log4cpp::Category& testCategory;
};

Log::Log(const string& filename, const string& path)
:fileppender(new log4cpp::FileAppender(filename,path+filename))
,testCategory(root.getInstance("testCategory"))
{
    log4cpp::PatternLayout* pLayout = new log4cpp::PatternLayout();
    pLayout->setConversionPattern("%d: %p %c %x: %m%n");     
    testCategory.addAppender(fileppender);
    testCategory.setPriority(log4cpp::Priority::INFO);
}

Log::~Log()
{
    log4cpp::Category::shutdown();
}

void Log::info(const string& msg)
{
    testCategory.info(msg);
}

void Log::warn(const string& msg)
{
    testCategory.warn(msg);
}

void Log::error(const string& msg)
{
    testCategory.error(msg);
}

log4cpp::Category& Log::root = log4cpp::Category::getRoot();

#if 0
void operator<<(Log& log, const string& words)
{

}
#endif
