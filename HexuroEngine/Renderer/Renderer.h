#ifndef _HEXURO_RENDERER_
#define _HEXURO_RENDERER_

#include "Window.h"
#include "Scene/Scene.h"
#include "OpenGL/VertexArray.h"
#include "OpenGL/IndexBuffer.h"
#include "OpenGL/Shader.h"
#include "OpenGL/Texture.h"

namespace Hexuro {

    class Renderer {
    public:
        static int Init(Window& window);

        static void FramebufferResizeCallback(GLFWwindow* window, int width, int height);

        static void Render(VertexArray vertexArray, IndexBuffer indexBuffer, Shader shader, Texture texture);

        static void SetUniform1f(const Shader& shader, const char* uniform, GLfloat value);

    private:
        static Window& m_Window;
    };

}

#endif