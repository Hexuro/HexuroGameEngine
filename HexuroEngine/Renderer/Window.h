#ifndef _HEXURO_WINDOW_
#define _HEXURO_WINDOW_

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "../Core/Log.h"

namespace Hexuro {
    class Window
    {
    public:
        int Init(int width, int height, const char* title);
        void Update();
        
        bool ShouldClose();

    private:
        GLFWwindow* m_window;
    };

}

#endif // !_HEXURO_WINDOW_