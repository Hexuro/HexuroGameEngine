#ifndef _HEXURO_APPLICATION_
#define _HEXURO_APPLICATION_

#include "Renderer/Window.h"

namespace Hexuro {
    class Application
    {
    public:
        Application() = default;
        virtual ~Application() = default;

        int Run();
        int Init();
        int Shutdown();

    private:
        Window m_Window;
    };

    // To be implemented by client
    Hexuro::Application* CreateApplication();
}

#endif // !_HEXURO_APPLICATION_