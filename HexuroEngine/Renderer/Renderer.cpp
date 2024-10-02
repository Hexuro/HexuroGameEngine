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

    void Renderer::Render(VertexArray VAO, IndexBuffer EBO, Shader shader, Texture TEX)
    {
        shader.Activate();
        TEX.Bind();
        VAO.Bind();

        glDrawElements(GL_TRIANGLES, EBO.GetSize(), GL_UNSIGNED_INT, 0);
    }

    void Renderer::SetUniform1f(const Shader& shader, const char* uniform, GLfloat value)
    {
        glUseProgram(shader.ID); //TODO: Remove
        glUniform1f(glGetUniformLocation(shader.ID, uniform), value);
    }
}