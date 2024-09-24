#include "pch.h"
#include "Texture.h"

#include "glad/glad.h"
#include "Core/Log.h"

namespace Hexuro {
    Texture::Texture(const char* filepath, bool genMipmap, GLenum slot, GLenum format)
    {
        glGenTextures(1, &ID);
        glActiveTexture(slot);
        glBindTexture(GL_TEXTURE_2D, ID);

        // str = xyz
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        stbi_set_flip_vertically_on_load(true);
        m_Data = stbi_load(filepath, &m_Width, &m_Height, &m_NumColorChannel, 0);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_Data);

        if (m_Data) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, format, GL_UNSIGNED_BYTE, m_Data);
            if (genMipmap)
                glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
            HX_ENGINE_ERROR("Failed to load texture: {0}", filepath);

        stbi_image_free(m_Data);
    }

    void Texture::SetUniform(Shader& shader, const char* uniform, GLuint unit)
    {
        GLuint theUniform = glGetUniformLocation(shader.ID, uniform);
        shader.Activate();
        glUniform1i(theUniform, unit);
    }
}