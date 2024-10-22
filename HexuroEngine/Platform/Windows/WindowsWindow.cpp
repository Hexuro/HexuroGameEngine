#include "pch.h"
#include "WindowsWindow.h"

#include "Core/Log.h"
#include "Core/Core.h"

namespace Hexuro {
    static bool s_GLFWIsInitialized = false;

    Window* Window::Create(const WindowProps& props)
    {
        return new WindowsWindow(props);
    }

    WindowsWindow::WindowsWindow(const WindowProps& props)
    {
        Init(props);
    }

    WindowsWindow::~WindowsWindow()
    {
        Shutdown();
    }

    void WindowsWindow::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(m_Handle);
    }

    void WindowsWindow::Init(const WindowProps& props)
    {
        m_Data.title = props.title;
        m_Data.width = props.width;
        m_Data.height = props.height;

        HX_GAME_INFO("Creating window {0} ({1}, {2})", props.title, props.width, props.height);

        if (!s_GLFWIsInitialized) {
            int success = glfwInit();
            HX_ENGINE_ASSERT(success, "Could not initialize GLFW!");
            s_GLFWIsInitialized = true;
        }

        m_Handle = glfwCreateWindow((int)props.width, (int)props.height, m_Data.title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_Handle);
        glfwSetWindowUserPointer(m_Handle, &m_Data);

    }
    void WindowsWindow::Shutdown()
    {
        glfwDestroyWindow(m_Handle);
    }
}