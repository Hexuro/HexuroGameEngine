#ifndef _HEXURO_APPLICATION_
#define _HEXURO_APPLICATION_

#include "Renderer/Window.h"
#include "Core/Layer.h"
#include "Core/LayerStack.h"

namespace Hexuro {
    struct ApplicationSpecification {
        std::string name;
    };

    class Application  {
    public:
        Application() = default;
        virtual ~Application() = default;

        virtual void InitLayers() = 0;
        void PushLayer(Layer* layer);
        
        int Run();
        int Shutdown();

    protected:
        int Init();

        Window m_Window;
        LayerStack m_LayerStack;

        float m_LastFrameTime = 0.0f;
    };

    // To be implemented by client
    Hexuro::Application* CreateApplication();
}

#endif // !_HEXURO_APPLICATION_