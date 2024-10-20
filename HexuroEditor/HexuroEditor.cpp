#include <iostream>
#include "HexuroEngine/HexuroEngine.h";

class EditorApp : public Hexuro::Application {
public:
    EditorApp() = default;
    ~EditorApp() override = default;
    void InitLayers() { };
};

Hexuro::Application* Hexuro::CreateApplication() { return new EditorApp; }