#ifndef MAINHANDLER_H
#define MAINHANDLER_H

#include "Thread.h"
#include "WebToolkit.h"
#include "OtherHandler.h"

class MainHandler
{
private:
    WebToolkit::Server server;
    WebToolkit::URIDispatcher dispatcher;
    CoreToolkit::Mutex entriesMutex;
    std::vector<std::string> entries;
    OtherHandler *soh;

public:
    MainHandler();
    void Run();
    void Index(WebToolkit::HttpServerContext* context);
    ~MainHandler()
    {
        delete soh;
    }
};

#endif // MAINHANDLER_H
