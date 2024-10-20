#ifndef _HEXURO_VERTEXBUFFER_
#define _HEXURO_VERTEXBUFFER_

#include "glad/glad.h"

namespace Hexuro {
    class VertexBuffer {
    public:
        GLuint ID;
        VertexBuffer(GLfloat* vertices, GLsizeiptr size);

        void Bind() { glBindBuffer(GL_ARRAY_BUFFER, ID); }
        void Unbind() { glBindBuffer(GL_ARRAY_BUFFER, 0); }
        void Delete() { glDeleteBuffers(1, &ID); }
    };
};

#endif