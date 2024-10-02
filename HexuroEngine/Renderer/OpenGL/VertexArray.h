#ifndef _HEXURO_OPENGL_VERTEXARRAY_
#define _HEXURO_OPENGL_VERTEXARRAY_

#include<glad/glad.h>
#include"VertexBuffer.h"

namespace Hexuro {
    class VertexArray {
    public:
        GLuint ID;

        VertexArray();

        //TODO: create the VertexBufferLayout class as a input til a function with the same name.
        void LinkAttribute(VertexBuffer& VertexBuffer, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);

        //TODO: Implement
        //void LinkPosition(VertexBuffer& VertexBuffer);
        //void LinkColor(VertexBuffer& VertexBuffer);
        //void LinkTexCoord(VertexBuffer& VertexBuffer);

        void Bind();
        void Unbind();
        void Delete();
    };

}

#endif