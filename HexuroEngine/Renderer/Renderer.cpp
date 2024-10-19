#include "pch.h"
#include "Renderer.h"

#include "Scene/Components.h"
#include "glad/glad.h"

namespace Hexuro {
    Window tempWindow;

    Window& Renderer::m_Window = tempWindow;

    int Renderer::Init(Window& window)
    {
        m_Window = window;
        HX_ENGINE_TRACE("Initialized the Hexuro Engine renderer");
        return 0;
    }

    void Renderer::FramebufferResizeCallback(GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }
}