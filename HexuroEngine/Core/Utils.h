#ifndef _HEXURO_UTILS_
#define _HEXURO_UTILS_

#include "GLFW/glfw3.h"

namespace Hexuro {
    struct Time {
        static float GetTime() { return glfwGetTime(); }
    };

    struct Vector2 {
        float x, y;
    };

    struct Vector3 {
        float x, y, z;
    };
    
    struct Vector4 {
        float x, y, z, w;
    };

}

#endif // !_HEXURO_UTILS_