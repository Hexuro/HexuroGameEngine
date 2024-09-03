#include "pch.h"
#include "Application.h"

#include "Renderer/Renderer.h"

namespace Hexuro {

    int Application::Run()
    {
        if (Init())
            HX_ENGINE_FATAL("Could not initialize the application");
        HX_ENGINE_INFO("Succesfully initialized the application");

        /* RENDERER SANDBOX CODE */
        GLfloat vertices[] = {
            -0.5f, -0.5f, 0.0f, // Bottom Left
             0.5f, -0.5f, 0.0f, // Bottom Right
             0.5f,  0.5f, 0.0f, // Top Right
            -0.5f,  0.5f, 0.0f  // Top Left
        };

        GLuint indices[] = {
            0, 1, 2, // First Triangle
            2, 3, 0  // Second Triangle
        };

        Shader shader("default.vert", "default.frag");
        VertexArray VAO;
        VAO.Bind();

        VertexBuffer VBO(vertices, sizeof(vertices));
        IndexBuffer EBO(indices, sizeof(indices));
        VAO.LinkVertexBuffer(VBO, 0);

        while (!m_Window.ShouldClose())
        {
            Renderer::Render(VAO, EBO, shader);
            m_Window.PollEvents();
        }

        return 0;
    }

    int Application::Init()
    {
        m_Window.Init(600, 600, "Hello, window!");
        Renderer::Init(m_Window);
        return 0;
    }
}