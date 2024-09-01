#include <iostream>
#include "HexuroEngine/HexuroEngine.h"

using namespace Hexuro;

class SandboxApp : public Hexuro::Application {
public:
    SandboxApp()
    {
#if ECS_EXAMPLE_CODE
        /* ECS Example code. This makes a runtime error but that should be ignored. */
        Hexuro::Scene* scene = new Hexuro::Scene;
        Hexuro::Entity entity = scene->CreateEntity("Test");
        entity.AddComponent<Hexuro::TransformComponent>();
        if (entity) {
            // Do stuff
        }
#endif
    }
    ~SandboxApp() override = default;
};

Hexuro::Application* Hexuro::CreateApplication() { return new SandboxApp; }