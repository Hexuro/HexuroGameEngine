#ifndef _HEXURO_RENDERER_
#define _HEXURO_RENDERER_

#include "Window.h"

namespace Hexuro {
    class Renderer {
    public:
        static int Init(Window& window);

    private:
        static Window& m_Window;
    };

}

#endif