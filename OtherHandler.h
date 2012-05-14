#ifndef OTHERHANDLER_H
#define OTHERHANDLER_H

#include "WebToolkit.h"

class OtherHandler
{
public:
    OtherHandler();
    void Handle(WebToolkit::HttpServerContext* context);
};

#endif // OTHERHANDLER_H
