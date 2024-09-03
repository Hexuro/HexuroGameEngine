#ifndef _HEXURO_OPENGL_INDEXBUFFER_
#define _HEXURO_OPENGL_INDEXBUFFER_

#include<glad/glad.h>

namespace Hexuro {
    class IndexBuffer {
    public:
        GLuint ID;

        IndexBuffer(GLuint* indices, GLsizeiptr size);

        void Bind();
        void Unbind();
        void Delete();
    };

}

#endif