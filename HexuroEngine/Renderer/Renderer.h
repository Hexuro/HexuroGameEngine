#ifndef _HEXURO_RENDERER_
#define _HEXURO_RENDERER_

#include "Window.h"
#include "Scene/Scene.h"
#include "OpenGL/VertexArray.h"
#include "OpenGL/IndexBuffer.h"
#include "OpenGL/Shader.h"

namespace Hexuro {

    class Renderer {
    public:
        static int Init(Window& window);

        static int Render(Scene* scene);
        static int Render(VertexArray vertexArray, IndexBuffer indexBuffer, Shader shader);

        static void FramebufferResizeCallback(GLFWwindow* window, int width, int height) { glViewport(0, 0, width, height); }

    private:
        static Window& m_Window;
    };

}

#endif