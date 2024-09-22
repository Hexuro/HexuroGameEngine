#include "pch.h"
#include "Camera.h"

namespace Hexuro {
    Camera::Camera(uint32_t width, uint32_t height, glm::vec3 pos)
    {
        m_WindowWidth = width;
        m_WindowHeight = height;
        position = pos;
    }

    void Camera::Matrix(float FOVdeg, float nearPlane, float farPlane, Shader& shader, const char* uniform)
    {
        glm::mat4 view = glm::mat4(1.0f);
        glm::mat4 projection = glm::mat4(1.0f);

        view = glm::lookAt(position, position + orientation, up);
        projection = glm::perspective(glm::radians(FOVdeg), (float)m_WindowWidth / m_WindowHeight, nearPlane, farPlane);

        glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(projection * view));
    }
}