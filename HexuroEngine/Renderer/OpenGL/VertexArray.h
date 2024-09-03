#ifndef _HEXURO_OPENGL_VERTEXARRAY_
#define _HEXURO_OPENGL_VERTEXARRAY_

#include<glad/glad.h>
#include"VertexBuffer.h"

namespace Hexuro {
    class VertexArray {
    public:
        GLuint ID;

        VertexArray();

        void LinkVertexBuffer(VertexBuffer& VertexBuffer, GLuint layout);

        void Bind();
        void Unbind();
        void Delete();
    };

}

#endif