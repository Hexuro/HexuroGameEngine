#include "pch.h"
#include "EditorCamera.h"

namespace Hexuro {
    uint32_t EditorCamera::m_WindowWidth;
    uint32_t EditorCamera::m_WindowHeight;

    EditorCamera::EditorCamera(uint32_t width, uint32_t height, glm::vec3 pos)
    {
        m_WindowWidth = width;
        m_WindowHeight = height;
        position = pos;
    }

    void EditorCamera::Matrix(float zoom, float nearPlane, float farPlane, Shader& shader, const char* uniform)
    {
        glm::mat4 view = glm::mat4(1.0f);
        glm::mat4 projection = glm::mat4(1.0f);

        view = glm::lookAt(position, position + orientation, up);
        projection = glm::perspective(glm::radians(zoom), (float)m_WindowWidth / m_WindowHeight, nearPlane, farPlane);

        glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(projection * view));
    }
    void EditorCamera::Inputs(GLFWwindow* window)
    {
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        {
            position += speed * -glm::normalize(glm::cross(orientation, up));
        }
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        {
            position += speed * glm::normalize(glm::cross(orientation, up));
        }
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        {
            position += speed * up;
        }
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        {
            position += speed * -up;
        }
        if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
        {
            position += speed * -orientation;
        }
        if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        {
            position += speed * orientation;
        }

    }
}