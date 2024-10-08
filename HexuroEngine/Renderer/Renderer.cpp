#include "pch.h"
#include "Renderer.h"

#include "Scene/Components.h"
#include "glad/glad.h"
#include "OpenGL/EditorCamera.h"

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

    void Renderer::FramebufferResizeCallback(GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);

        int windowWidth;
        int windowHeight;

        glfwGetWindowSize(window, &windowWidth, &windowHeight);

        EditorCamera::m_WindowHeight = windowHeight;
        EditorCamera::m_WindowWidth = windowWidth;
    }

    void Renderer::SetUniform1f(const Shader& shader, const char* uniform, GLfloat value)
    {
        glUseProgram(shader.ID); //TODO: Remove
        glUniform1f(glGetUniformLocation(shader.ID, uniform), value);
    }
}