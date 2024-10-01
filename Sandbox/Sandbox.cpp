#include <iostream>
#include "HexuroEngine/HexuroEngine.h"

using namespace Hexuro;

struct TestLayer : public Hexuro::Layer {
    TestLayer();
    void OnAttach() override {};             
    void OnDetach() override {}
    void OnUpdate(Timestep ts) override {}
    void OnRender() override {}

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
};

class SandboxApp : public Hexuro::Application {
public:
    SandboxApp()
    {
        PushLayer(new TestLayer());
    }
};

Hexuro::Application* Hexuro::CreateApplication() { return new SandboxApp; }