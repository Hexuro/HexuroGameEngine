#ifndef _HEXURO_APPLICATION_
#define _HEXURO_APPLICATION_

#include "Core/LayerStack.h"
#include "Core/Window.h"
#include "Events/ApplicationEvent.h"

namespace Hexuro {
    struct ApplicationSpecification {
        std::string name;
    };

    class Application  {
    public:
        Application() = default;
        virtual ~Application() = default;

        void PushLayer(Layer* layer);
        
        int Run();
        void OnEvent(Event& e);

    protected:
        int Init();
        int Shutdown();

        std::unique_ptr<Window> m_Window;
        LayerStack m_LayerStack;
        float m_LastFrameTime = 0.0f;
        bool m_Running = true;

        bool OnWindowClose(WindowCloseEvent& event);
    };

    // To be implemented by client
    Hexuro::Application* CreateApplication();
}

#endif // !_HEXURO_APPLICATION_