#include "OtherHandler.h"

OtherHandler::OtherHandler()
{
}

void OtherHandler::Handle(WebToolkit::HttpServerContext *context)
{
    context->responseBody<<"<html><body><h1>Other controller</h1>";
    context->responseBody<<"<h3>Сдесь мы можем наблюдать то как наш контроллер страницы обработал запрос и выдал ответ да)</h3>";
    context->responseBody<<"</body></html>";
}
