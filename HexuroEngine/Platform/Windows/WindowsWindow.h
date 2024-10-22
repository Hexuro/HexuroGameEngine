#ifndef _HEXURO_WINDOWSWINDOW_
#define _HEXURO_WINDOWSWINDOW_

#include "Core/Window.h"

namespace Hexuro {
    class WindowsWindow : public Window {
    public:
        WindowsWindow(const WindowProps& properties);
        virtual ~WindowsWindow();

        void OnUpdate() override;

        uint32_t GetWidth() const override { return m_Data.width; }
        uint32_t GetHeight() const override { return m_Data.height; }

        void* GetNative() const override { return m_Handle; }
        void SetEventCallback(const EventCallbackFunction& callback) { m_Data.eventCallback = callback; }

    private:
        struct WindowData {
            std::string title;
            uint32_t width, height;
            EventCallbackFunction eventCallback;
        };
        WindowData m_Data;

        virtual void Init(const WindowProps& props);
        virtual void Shutdown();
        GLFWwindow* m_Handle;
    };

}

#endif