#ifndef _HEXURO_APPLICATION_
#define _HEXURO_APPLICATION_

#include "Renderer/Window.h"
#include "Core/Layer.h"
#include "Core/LayerStack.h"

namespace Hexuro {
    class Application
    {
    public:
        Application() = default;
        virtual ~Application() = default;

        void PushLayer(Layer* layer);
        
        int Run();
        int Shutdown();

    protected:
        int Init();

        Window m_Window;
        LayerStack m_LayerStack;
    };

    // To be implemented by client
    Hexuro::Application* CreateApplication();
}

#endif // !_HEXURO_APPLICATION_