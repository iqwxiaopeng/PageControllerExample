#include"MainHandler.h"
#include"OSUtils.h"

int main()
{
    try
    {
        MainHandler app;
        app.Run();
        CoreToolkit::Environment::WaitForTermination();
    }
    catch(std::exception& e)
    {
        LOG(CoreToolkit::LogError)<<e.what();
    }
}
