#include "pch.h"
#include "Window.h"

#include "Renderer/Renderer.h"

namespace Hexuro {

    int Window::Init(int width, int height, const char* title)
    {
        if (!glfwInit())
            HX_ENGINE_FATAL("Could not initialize GLFW");

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_WindowHandle = glfwCreateWindow(width, height, title, nullptr, nullptr);
        if (m_WindowHandle == NULL) {
            glfwTerminate();
            HX_ENGINE_FATAL("Could not create GLFW window");
            system("PAUSE");
        }

        glfwMakeContextCurrent(m_WindowHandle);
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            HX_ENGINE_FATAL("Failed to initialize GLAD");
            return -1;
        }
        glViewport(0, 0, width, height);

        /* Setting GLFW callbacks */
        glfwSetFramebufferSizeCallback(m_WindowHandle, Renderer::FramebufferResizeCallback);

        HX_ENGINE_TRACE("Initialized the Hexuro Engine window");
        return 0;
    }

    void Window::OnUpdate()
    {
        glad_glClearColor(1, 1, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(m_WindowHandle);
        PollEvents();
    }

    bool Window::ShouldClose()
    {
        if (glfwWindowShouldClose(m_WindowHandle))
            return true;
        return false;
    }


}