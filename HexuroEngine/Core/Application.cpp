#include "pch.h"
#include "Application.h"

#include "Renderer/Renderer.h"
#include "Renderer/OpenGL/EditorCamera.h"
#include "stb/stb_image.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

namespace Hexuro {

    int Application::Run()
    {
        if (Init())
            HX_ENGINE_FATAL("Could not initialize the application");
        HX_ENGINE_INFO("Succesfully initialized the application");

        /* RENDERER SANDBOX CODE */

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
            0, 3, 2  // Lower triangle
        };

        Shader shader("default.vert", "default.frag");
        VertexArray VAO;
        VAO.Bind();

        VertexBuffer VBO(vertices, sizeof(vertices));
        IndexBuffer EBO(indices, sizeof(indices));
        VAO.LinkAttribute(VBO, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);                    // Position
        VAO.LinkAttribute(VBO, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));  // Color
        VAO.LinkAttribute(VBO, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));  // Texure

        Texture texture("Grass_Block.jpg", true, GL_TEXTURE0, GL_RGB);
        texture.SetUniform(shader, "tex0", 0);

        EditorCamera camera(m_Window.GetWidth(), m_Window.GetHeight(), glm::vec3(0.0f, 0.0f, 2.0f));

        while (!m_Window.ShouldClose())
        {
            m_Window.PollEvents();

            camera.Inputs(m_Window.GetHandle());
            camera.Matrix(90.0f, 0.1f, 100.0f, shader, "cameraMatrix", m_Window);
            Renderer::Render(VAO, EBO, shader, texture);
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