#ifndef _HEXURO_WINDOW_
#define _HEXURO_WINDOW_

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Core/Log.h"
#include "Events/Event.h"

namespace Hexuro {
    struct WindowProps {
        std::string title;
        uint32_t width;
        uint32_t height;

        WindowProps(const std::string& Title = "Hexuro Engine",  uint32_t Width = 1600, uint32_t Height = 900) : title(Title), width(Width), height(Height) {}
    };

    class Window {
    public:
        using EventCallbackFunction = std::function<void(Event&)>;

        virtual ~Window() = default;

        virtual void OnUpdate() = 0;
        virtual uint32_t GetWidth() const = 0;
        virtual uint32_t GetHeight() const = 0;

        virtual void SetEventCallback(const EventCallbackFunction& callback) = 0;
        virtual void* GetNative() const = 0;

        static Window* Create(const WindowProps& props = WindowProps());
    };

}

#endif // !_HEXURO_WINDOW_