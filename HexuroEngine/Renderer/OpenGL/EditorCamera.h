#ifndef _HEXURO_CAMERA_
#define _HEXURO_CAMERA_

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>
#include <stdint.h>
#include "Shader.h"
#include "Renderer/Window.h"

namespace Hexuro {
    class EditorCamera {
    public:
        EditorCamera(uint32_t width, uint32_t height, glm::vec3 pos);

        // Updates and exports the camera matrix to the Vertex Shader
        void Matrix(float FOVdeg, float nearPlane, float farPlane, Shader& shader, const char* uniform, const Window& window);
        void Inputs(GLFWwindow* window);

        glm::vec3 position;
        glm::vec3 orientation = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

        float speed = 0.01f;
        float sensitivity = 100.0f;

        static uint32_t m_WindowWidth;
        static uint32_t m_WindowHeight;
    };

}

#endif