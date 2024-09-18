#include "pch.h"
#include "Texture.h"

#include "glad/glad.h"
#include "Core/Log.h"

namespace Hexuro {
    Texture::Texture(const char* filepath, bool genMipmap)
    {
        //TODO(ViktorPopp): finish shader tutorial
        glGenTextures(1, &ID);
        glBindTexture(GL_TEXTURE_2D, ID);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        m_Data = stbi_load(filepath, &m_Width, &m_Height, &m_NumColorChannel, 0);

        if (m_Data) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_Width, m_Height, 0, GL_RGB, GL_UNSIGNED_BYTE, m_Data);
            if (genMipmap)
                glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
            HX_ENGINE_ERROR("Failed to load texture: {0}", filepath);
    }
}