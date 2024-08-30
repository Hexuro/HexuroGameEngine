#include <iostream>
#include "entt/entt.hpp"

void enttsandbox();

int main()
{

}

void enttsandbox() {
    struct ExampleComponent {
        ExampleComponent(uint32_t x, uint32_t y) : blabla(x), blabla2(y) {}
        uint32_t blabla;
        uint32_t blabla2;
        operator uint32_t () { return blabla; }
        operator const uint32_t const () { return blabla; }
    };

    entt::registry registry;    // Creating a registry
    entt::entity e = registry.create();     // Creating a entity
    registry.emplace<ExampleComponent>(e, ExampleComponent(1, 1));  // Adding a component
    if (registry.all_of<ExampleComponent>(e)) // Checking for component before getting
        registry.get<ExampleComponent>(e); // Getting a component
    registry.remove<ExampleComponent>(e); // Removing a component

    auto view = registry.view<ExampleComponent>();
    for (auto entity : view) // for each entity that has ExampleComponent
        ExampleComponent& booo = view.get<ExampleComponent>(entity);

    // REFER CHERNO VIDEO   

}