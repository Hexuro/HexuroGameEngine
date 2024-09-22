#include "pch.h"
#include "Camera.h"

namespace Hexuro {
    Camera::Camera(int window_width, int window_height, glm::vec3 initialPosition)
    {
        windowHeight = window_height;
        windowWidth = window_width;
        position = initialPosition;
    }
    void Camera::Matrix(float FOVdeg, float nearPlane, float farPlane, Shader& shader, const char* uniform, const Window& window)
    {
        glm::mat4 view = glm::mat4(1.0f);
        glm::mat4 projection = glm::mat4(1.0f);

        view = glm::lookAt(position, position + orientation, up);
        projection = glm::perspective(glm::radians(FOVdeg), (float)window.GetWidth() / window.GetHeight(), nearPlane, farPlane);

        glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(projection * view));
    }
}