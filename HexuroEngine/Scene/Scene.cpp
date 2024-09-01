#include "pch.h"
#include "Scene.h"

#include "Entity.h"

namespace Hexuro {
    Scene::Scene() {

    }

    Scene::~Scene()
    {
    }

    Entity Scene::CreateEntity(const std::string name)
    {
        Entity entity = { m_Registry.create(), this };
        entity.AddComponent<TransformComponent>();
        auto& tag = entity.AddComponent<TagComponent>();
        tag.tag = name.empty() ? "Unnamed Entity" : name;
        return entity;
    }

    void Scene::Update() // Update should not render. after scene has been updated call Renderer.Render() method.
    {
    }

}
