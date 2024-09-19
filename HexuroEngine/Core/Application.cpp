#include "pch.h"
#include "Application.h"

#include "Renderer/Renderer.h"
#include "stb/stb_image.h"

namespace Hexuro {

    int Application::Run()
    {
        if (Init())
            HX_ENGINE_FATAL("Could not initialize the application");
        HX_ENGINE_INFO("Succesfully initialized the application");

        /* RENDERER SANDBOX CODE */
        // Vertices coordinates
        GLfloat vertices[] =
        { //     COORDINATES     /        COLORS      /   TexCoord  //
            -0.5f, -0.5f, 0.0f,     1.0f, 0.0f, 0.0f,	0.0f, 0.0f, // Lower left corner
            -0.5f,  0.5f, 0.0f,     0.0f, 1.0f, 0.0f,	0.0f, 1.0f, // Upper left corner
             0.5f,  0.5f, 0.0f,     0.0f, 0.0f, 1.0f,	1.0f, 1.0f, // Upper right corner
             0.5f, -0.5f, 0.0f,     1.0f, 1.0f, 1.0f,	1.0f, 0.0f  // Lower right corner
        };
        GLuint indices[] =
        {
            0, 2, 1, // Upper triangle
            0, 3, 2 // Lower triangle
        };

        Shader shader("default.vert", "default.frag");
        VertexArray VAO;
        VAO.Bind();

        VertexBuffer VBO(vertices, sizeof(vertices));
        IndexBuffer EBO(indices, sizeof(indices));
        VAO.LinkAttribute(VBO, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
        VAO.LinkAttribute(VBO, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
        VAO.LinkAttribute(VBO, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));

        GLuint scaleUniform = glGetUniformLocation(shader.ID, "scale");
        GLuint texture0Uniform = glGetUniformLocation(shader.ID, "tex0");

        Texture texture("Grass_Block.jpg", true);

        while (!m_Window.ShouldClose())
        {
            //TODO: Remove
            {
                shader.Activate();
                glUniform1f(scaleUniform, 0.5);
                glUniform1f(texture0Uniform, 0);
                
            }
            Renderer::Render(VAO, EBO, shader, texture);
            m_Window.PollEvents();
        }

        if (!Shutdown())
            return 0;
    }

    int Application::Init()
    {
        m_Window.Init(600, 600, "Hello, window!");
        Renderer::Init(m_Window);
        return 0;
    }

    int Application::Shutdown()
    {
        HX_ENGINE_INFO("Succesfully terminated the application");
        return 0;
    }
}