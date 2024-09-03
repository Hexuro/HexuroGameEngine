#ifndef _HEXURO_OPENGL_VERTEXBUFFER_
#define _HEXURO_OPENGL_VERTEXBUFFER_

#include "glad/glad.h"

namespace Hexuro {
    class VertexBuffer {
    public:
        GLuint ID;

        VertexBuffer(GLfloat* vertices, GLsizeiptr size);

        void Bind();
        void Unbind();
        void Delete();
    };

}

#endif