#include <iostream>Textur
#include "HexuroEngine/HexuroEngine.h"

using namespace Hexuro;

struct TestLayer : public Hexuro::Layer {
    TestLayer() :
                    VBO(vertices, sizeof(vertices)), EBO(indices, sizeof(indices)),
                    texture("Grass_Block.jpg", true, GL_TEXTURE0, GL_RGB),
                    camera(600, 600, glm::vec3(0.0f, 0.0f, 2.0f)) {}
    void OnAttach() override {
        VAO.LinkAttribute(VBO, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);                    // Position
        VAO.LinkAttribute(VBO, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));  // Color
        VAO.LinkAttribute(VBO, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));  // Texure
        texture.SetUniform(shader, "tex0", 0);
    };             
    void OnDetach() override {}

    void OnUpdate(Timestep ts) override {
        camera.Matrix(90.0f, 0.1f, 100.0f, shader, "cameraMatrix");
    }
    void OnUpdate() {
        camera.Matrix(90.0f, 0.1f, 100.0f, shader, "cameraMatrix");
    }
    void OnRender() override {
        HX_GAME_TRACE("Renders");
        Renderer::Render(VAO, EBO, shader, texture);
    }

    GLfloat vertices[8*4] = {
      //     COORDINATES     /        COLORS      /   TexCoord  //
        -0.5f, -0.5f, 0.0f,     1.0f, 0.0f, 0.0f,	0.0f, 0.0f, // Lower left corner
        -0.5f,  0.5f, 0.0f,     0.0f, 1.0f, 0.0f,	0.0f, 1.0f, // Upper left corner
         0.5f,  0.5f, 0.0f,     0.0f, 0.0f, 1.0f,	1.0f, 1.0f, // Upper right corner
         0.5f, -0.5f, 0.0f,     1.0f, 1.0f, 1.0f,	1.0f, 0.0f  // Lower right corner
    };
    GLuint indices[3*2] = {
        0, 2, 1, // Upper triangle
        0, 3, 2  // Lower triangle
    };
    Shader shader;
    VertexArray VAO;
    VertexBuffer VBO;
    IndexBuffer EBO;
    Texture texture;
    EditorCamera camera;
};

class SandboxApp : public Hexuro::Application {
public:
    void InitializeLayers() override {
        PushLayer(new TestLayer());
    }
};

Hexuro::Application* Hexuro::CreateApplication() { return new SandboxApp; }