#include <iostream>
#include "HexuroEngine/HexuroEngine.h"

using namespace Hexuro;

struct TestLayer : public Hexuro::Layer {
    void OnAttach() override {}             
    void OnDetach() override {}
    void OnUpdate(Timestep ts) override {}
    void OnRender() override {}
};

class SandboxApp : public Hexuro::Application {
public:
    SandboxApp() {
        PushLayer(new TestLayer());
    }
};

Hexuro::Application* Hexuro::CreateApplication() { return new SandboxApp; }