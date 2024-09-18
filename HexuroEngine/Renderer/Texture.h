#ifndef _HEXURO_TEXTURE_
#define _HEXURO_TEXTURE_

#include "stb/stb_image.h"

namespace Hexuro {
    class Texture {
    public:
        unsigned int ID;

        Texture() {}
        Texture(const char* filepath, bool genMipmap);

    private:
        int m_Height, m_Width;
        int m_NumColorChannel;
        unsigned char* m_Data;
    };

}

#endif