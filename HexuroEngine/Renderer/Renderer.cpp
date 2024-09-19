#include "pch.h"
#include "Renderer.h"

#include "Scene/Components.h"

namespace Hexuro {
    Window tempWindow;

    Window& Renderer::m_Window = tempWindow;

    int Renderer::Init(Window& window)
    {
        m_Window = window;
        HX_ENGINE_TRACE("Initialized the Hexuro Engine renderer");
        return 0;
    }

    int Renderer::Render(Scene* scene)
    {
        auto view = scene->m_Registry.view<SpriteComponent, TransformComponent>();
        for (auto entity : view) {

        }

        return 0;
    }

    int Renderer::Render(VertexArray vertexArray, IndexBuffer indexBuffer, Shader shader)
    {
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.Activate();
        vertexArray.Bind();

        glDrawElements(GL_TRIANGLES, indexBuffer.GetSize(), GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(m_Window.m_WindowHandle);

        return 0;
    }

    int Renderer::Render(VertexArray vertexArray, IndexBuffer indexBuffer, Shader shader, Texture texture)
    {
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.Activate();
        texture.Bind();
        vertexArray.Bind();

        glDrawElements(GL_TRIANGLES, indexBuffer.GetSize(), GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(m_Window.m_WindowHandle);

        return 0;
    }
}