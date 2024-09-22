#include "pch.h"
#include "Application.h"

#include "Renderer/Renderer.h"
#include "Renderer/OpenGL/Camera.h"
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

        Texture texture("Grass_Block.jpg", true, GL_TEXTURE0, GL_RGB);
        texture.SetUniform(shader, "tex0", 0);

        //Camera camera(m_Window.GetWidth(), m_Window.GetHeight(), glm::vec3(0.0f, 0.0f, 2.0f));

        while (!m_Window.ShouldClose())
        {
            glm::mat4 modelMatrix = glm::mat4(1.0f);
            glm::mat4 viewMatrix = glm::mat4(1.0f);
            glm::mat4 projectionMatrix = glm::mat4(1.0f);

            viewMatrix = glm::translate(viewMatrix, glm::vec3(0.0f, -0.5f, -2.0f));
            projectionMatrix = glm::perspective(glm::radians(45.0f), (float)(m_Window.GetWidth() / (float)m_Window.GetHeight()), 0.1f, 100.0f);

            glUniformMatrix4fv(glGetUniformLocation(shader.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix));
            glUniformMatrix4fv(glGetUniformLocation(shader.ID, "viewMatrix"), 1, GL_FALSE, glm::value_ptr(viewMatrix));
            glUniformMatrix4fv(glGetUniformLocation(shader.ID, "projectionMatrix"), 1, GL_FALSE, glm::value_ptr(projectionMatrix));

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