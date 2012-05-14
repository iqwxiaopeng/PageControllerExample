#ifndef MAINHANDLER_H
#define MAINHANDLER_H

#include "Thread.h"
#include "WebToolkit.h"

class MainHandler
{
private:
    WebToolkit::Server server;
    WebToolkit::URIDispatcher dispatcher;
    CoreToolkit::Mutex entriesMutex;
    std::vector<std::string> entries;

public:
    MainHandler();
    void Run();
    void Index(WebToolkit::HttpServerContext* context);
};

#endif // MAINHANDLER_H
