#include "pch.h"
#include "WindowsWindow.h"

#include "Core/Log.h"
#include "Core/Core.h"

#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"

namespace Hexuro {
    static bool s_GLFWIsInitialized = false;
    static void GLFWErrorCallback(int error, const char* description)
    {
        HX_ENGINE_ERROR("GLFW Error {0}: {1}", error, description);
    }

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
            glfwSetErrorCallback(GLFWErrorCallback);
            s_GLFWIsInitialized = true;
        }

        m_Handle = glfwCreateWindow((int)props.width, (int)props.height, m_Data.title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_Handle);
        glfwSetWindowUserPointer(m_Handle, &m_Data);

        // GLFW Callbacks
        glfwSetWindowSizeCallback(m_Handle, [](GLFWwindow* window, int width, int height) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            WindowResizeEvent e(width, height);

            data.width = width;
            data.height = height;
            data.eventCallback(e);
            });
        glfwSetWindowCloseCallback(m_Handle, [](GLFWwindow* window) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            WindowCloseEvent event;
            data.eventCallback(event);
            });
        glfwSetKeyCallback(m_Handle, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            //TODO: Convert to custom keycodes

            switch (action) {
            case GLFW_PRESS:
            {
                KeyPressedEvent event(key, 0);
                data.eventCallback(event);
                break;
            }
            case GLFW_RELEASE:
            {
                KeyReleasedEvent event(key);
                data.eventCallback(event);
                break;
            }
            case GLFW_REPEAT:
            {
                KeyPressedEvent event(key, 1);
                data.eventCallback(event);
                break;
            }
            }
            });
        glfwSetMouseButtonCallback(m_Handle, [](GLFWwindow* window, int button, int action, int mods) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            switch (action) {
            case GLFW_PRESS:
            {
                MouseButtonPressedEvent e(button);
                data.eventCallback(e);
                break;
            }
            case GLFW_RELEASE:
            {
                MouseButtonReleasedEvent e(button);
                data.eventCallback(e);
                break;
            }
            }
            });
        glfwSetScrollCallback(m_Handle, [](GLFWwindow* window, double xoffset, double yoffset) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            MouseScrolledEvent e((float)xoffset, (float)yoffset);
            data.eventCallback(e);
            });
        glfwSetCursorPosCallback(m_Handle, [](GLFWwindow* window, double xpos, double ypos) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            MouseMovedEvent e(xpos, ypos);
            data.eventCallback(e);
            });
    }
    void WindowsWindow::Shutdown()
    {
        glfwDestroyWindow(m_Handle);
    }
}