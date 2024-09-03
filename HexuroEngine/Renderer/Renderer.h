#ifndef _HEXURO_RENDERER_
#define _HEXURO_RENDERER_

#include "Window.h"
#include "OpenGL/VertexArray.h"
#include "OpenGL/IndexBuffer.h"
#include "OpenGL/Shader.h"

namespace Hexuro {
    class Renderer {
    public:
        static int Init(Window& window);

        static int Render(VertexArray vertexArray, IndexBuffer indexBuffer, Shader shader);

    private:
        static Window& m_Window;
    };

}

#endif