#include "MainHandler.h"

using namespace std;
using namespace CoreToolkit;
using namespace WebToolkit;

MainHandler::MainHandler():server(), dispatcher()
{
    dispatcher.AddMapping("/index",HttpGet,new HttpHandlerConnector<MainHandler>(this,&MainHandler::Index),true);
}

void MainHandler::Index(HttpServerContext* context)
{
    context->responseBody<<"<html><body><h1>SimpleBlog</h1><h3>Blog entries:</h3>";
    {
        MutexLock lock(entriesMutex);
        for(size_t i=0;i<entries.size();i++)
        {
            context->responseBody<<"<div class=\"entry\">";
            context->responseBody<<"<div class=\"author\"><b>";
            //context->responseBody<<entries[i].author;
            context->responseBody<<" wrote:";
            context->responseBody<<"</b></div>";
            context->responseBody<<"<div class=\"text\">";
            //context->responseBody<<entries[i].text;
            context->responseBody<<"</div></div>";
        }
    }
    context->responseBody<<"<h3>Add new entry:</h3>";
    context->responseBody<<"<form method=\"post\" action=\"/post\">";
    context->responseBody<<"<table>";
    context->responseBody<<"<tr><td>Author:</td><td><input type=\"text\" name=\"author\"></td></tr>";
    context->responseBody<<"<tr><td>Text:</td><td><textarea name=\"text\"></textarea></td>";
    context->responseBody<<"<tr><td><input type=\"submit\" value=\"Submit\"></td></tr>";
    context->responseBody<<"</table>";
    context->responseBody<<"</form>";
    context->responseBody<<"</body></html>";
}
