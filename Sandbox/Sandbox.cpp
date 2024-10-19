#include <iostream>
#include "HexuroEngine/HexuroEngine.h"

using namespace std;
using namespace Hexuro;

struct TestLayer : public Hexuro::Layer {
    void OnAttach() override { HX_GAME_INFO("Pushed layer"); }  
    void OnDetach() override { HX_GAME_INFO("Detatched layer"); }
    void OnUpdate(Timestep ts) override { }
    void OnRender() override { }
};

class SandboxApp : public Hexuro::Application {
public:
    void InitLayers() {
        PushLayer(new TestLayer());
    }
};

Hexuro::Application* Hexuro::CreateApplication() { return new SandboxApp; }