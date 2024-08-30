#ifndef _HEXURO_APPLICATION_
#define _HEXURO_APPLICATION_

#include "../Renderer/Window.h"

namespace Hexuro {
    class Application
    {
    public:
        Application() = default;
        Application(std::string projectFile); //TODO: Make this and make the editor app open fromm it's HexuroEditor.hexproj file
        virtual ~Application() = default;

        int Run();

    private:
        int Init();

        Window m_Window;
    };

    // To be implemented by client
    Hexuro::Application* CreateApplication();
}

#endif // !_HEXURO_APPLICATION_