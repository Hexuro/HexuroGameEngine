#ifndef _HEXURO_CAMERA_
#define _HEXURO_CAMERA_

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>
#include"Shader.h"
#include "Renderer/Window.h"

namespace Hexuro {
    class Camera {
    public:
        glm::vec3 position;
        glm::vec3 orientation = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

        // Prevents the camera from jumping around when first clicking left click
        bool firstClick = true;

        uint32_t windowWidth;
        uint32_t windowHeight;

        float speed = 0.1f;
        float sensitivity = 100.0f;

        Camera(int window_width, int window_height, glm::vec3 position);

        // Updates and exports the camera matrix to the Vertex Shader
        void Matrix(float FOVdeg, float nearPlane, float farPlane, Shader& shader, const char* uniform, const Window& window);
        // Handles camera inputs
        void Inputs(GLFWwindow* window);
    };

}

#endif