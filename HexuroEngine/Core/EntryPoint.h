#ifndef _HEXURO_ENTRYPOINT_
#define _HEXURO_ENTRYPOINT_

#include "Application.h"
#include "Log.h"

extern Hexuro::Application* Hexuro::CreateApplication();

int main(int argc, char** argv)
{
    Hexuro::Log::Init();
    Hexuro::Application* app = Hexuro::CreateApplication();
    HX_ENGINE_INFO("Succesfully initialized the Hexuro Engine");

    return app->Run();
}

#endif // !_HEXURO_ENTRYPOINT_