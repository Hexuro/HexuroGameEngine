#ifndef _HEXURO_TEXTURE_
#define _HEXURO_TEXTURE_

#include "stb/stb_image.h"
#include "glad/glad.h"

namespace Hexuro {
    class Texture {
    public:
        uint32_t ID;

        Texture(const char* filepath, bool genMipmap);

        void Bind()  { glBindTexture(GL_TEXTURE_2D, ID); }
        void UnBind() { glBindTexture(GL_TEXTURE_2D, 0); }
        void Delete() { glDeleteTextures(1, &ID); }

    private:
        int m_Height, m_Width;
        int m_NumColorChannel;
        unsigned char* m_Data;
    };

}

#endif