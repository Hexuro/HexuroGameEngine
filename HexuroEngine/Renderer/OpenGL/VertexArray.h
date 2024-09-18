#ifndef _HEXURO_OPENGL_VERTEXARRAY_
#define _HEXURO_OPENGL_VERTEXARRAY_

#include<glad/glad.h>
#include"VertexBuffer.h"

namespace Hexuro {
    class VertexArray {
    public:
        GLuint ID;

        VertexArray();

        //TODO: create the VertexBufferLayout class as another input.
        void LinkAttribute(VertexBuffer& VertexBuffer, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);

        void Bind();
        void Unbind();
        void Delete();
    };

}

#endif