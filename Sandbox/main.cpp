#include <iostream>
#include "HexuroEngine/HexuroEngine.h"

using namespace Hexuro;

class SandboxApp : public Hexuro::Application {
public:
    SandboxApp() = default;
    ~SandboxApp() override = default;
};

Hexuro::Application* Hexuro::CreateApplication() { return new SandboxApp; }