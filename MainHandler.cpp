#include "MainHandler.h"
#include "OtherHandler.h"

using namespace std;
using namespace CoreToolkit;
using namespace WebToolkit;

MainHandler::MainHandler():server(), dispatcher()
{
    soh = new OtherHandler;
    dispatcher.AddMapping("/index",HttpGet,new HttpHandlerConnector<MainHandler>(this,&MainHandler::Index),true);
    dispatcher.AddMapping("/OtherController",HttpPost,new HttpHandlerConnector<OtherHandler>(soh,&OtherHandler::Handle),true);

    server.RegisterHandler(&dispatcher);
}

void MainHandler::Index(HttpServerContext* context)
{
    context->responseBody<<"<html><body><h1>PageControllerExample</h1>";

    context->responseBody<<"<form method=\"post\" action=\"/OtherController\">";
    context->responseBody<<"<input type=\"submit\" value=\"Go to the another controller\">";
    context->responseBody<<"</form>";
    context->responseBody<<"</body></html>";
}

void MainHandler::Run()
{
    server.Run();
}
