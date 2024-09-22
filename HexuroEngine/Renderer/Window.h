#ifndef _HEXURO_WINDOW_
#define _HEXURO_WINDOW_

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Core/Log.h"

namespace Hexuro {
    namespace Callbacks {

    }

    class Window
    {
    public:
        Window() = default;

        int Init(int width, int height, const char* title);
        void Update();

        void PollEvents() { glfwPollEvents(); }
        bool ShouldClose();

        uint32_t GetWidth() const { int w, h; glfwGetWindowSize(m_WindowHandle, &w, &h); return w; }
        uint32_t GetHeight() const { int w, h; glfwGetWindowSize(m_WindowHandle, &w, &h); return h; }

    private:
        GLFWwindow* m_WindowHandle = nullptr;

        friend class Renderer;
    };

}

#endif // !_HEXURO_WINDOW_