#include "Window.h"

namespace Hexuro {
    int Window::Init(int width, int height, const char* title)
    {
        if (!glfwInit())
            HX_ENGINE_FATAL("Could not initialize GLFW");

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_window = glfwCreateWindow(width, height, title, nullptr, nullptr);
        if (m_window == NULL) {
            glfwTerminate();
            HX_ENGINE_FATAL("Could not create GLFW window");
        }

        glfwMakeContextCurrent(m_window);
        gladLoadGL();
        glViewport(0, 0, width, height);

        HX_ENGINE_TRACE("Initialized the Hexuro Engine window");
        return 0;
    }

    void Window::Update()
    {
        glClearColor(1, 1, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }

    bool Window::ShouldClose()
    {
        if (glfwWindowShouldClose(m_window))
            return true;
        return false;
    }

}