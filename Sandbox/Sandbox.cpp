#include <iostream>
#include "HexuroEngine/HexuroEngine.h"

using namespace Hexuro;

class SandboxApp;

struct TestLayer : public Hexuro::Layer {

};

class SandboxApp : public Hexuro::Application {
public:
    SandboxApp()
    {
        PushLayer(new TestLayer());
    }
};

Hexuro::Application* Hexuro::CreateApplication() { return new SandboxApp; }