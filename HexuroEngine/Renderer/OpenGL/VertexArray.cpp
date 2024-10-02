#include "pch.h"
#include "VertexArray.h"

namespace Hexuro {
    VertexArray::VertexArray()
    {
        glGenVertexArrays(1, &ID);
    }

    void VertexArray::LinkAttribute(VertexBuffer& VertexBuffer, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset)
    {
        VertexBuffer.Bind();
        glVertexAttribPointer(layout, numComponents, GL_FLOAT, type, stride, offset);
        glEnableVertexAttribArray(layout);
        VertexBuffer.Unbind();
    }

    void VertexArray::Bind()
    {
        glBindVertexArray(ID);
    }

    void VertexArray::Unbind()
    {
        glBindVertexArray(0);
    }

    void VertexArray::Delete()
    {
        glDeleteVertexArrays(1, &ID);
    }

}