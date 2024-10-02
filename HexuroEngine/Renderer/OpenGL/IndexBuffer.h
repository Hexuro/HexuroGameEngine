#ifndef _HEXURO_OPENGL_INDEXBUFFER_
#define _HEXURO_OPENGL_INDEXBUFFER_

#include<glad/glad.h>

namespace Hexuro {
    class IndexBuffer {
    public:
        GLuint ID;


        IndexBuffer() = default;
        IndexBuffer(GLuint* indices, GLsizeiptr size);
        IndexBuffer(GLuint* indices);

        static IndexBuffer Create(GLuint* indices, GLsizeiptr size) { return IndexBuffer(indices); }
        static IndexBuffer Create(GLuint* indices)                  { return IndexBuffer(indices); }

        void Bind();
        void Unbind();
        void Delete();

        uint32_t GetSize() { return m_BufferSize; }

    private:
        uint32_t m_BufferSize; // Size of indicies
    };

}

#endif