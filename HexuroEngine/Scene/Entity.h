#ifndef _HEXURO_ENTITY_
#define _HEXURO_ENTITY_

#include "Scene.h"
#include "Core/Log.h"
#include "entt/entt.hpp"

namespace Hexuro {
    class Entity {
    public:
        Entity() = default;
        Entity(entt::entity entity, Scene* scene);
        Entity(const Entity& rhs) = default;

        template<typename T, typename... Args> T& AddComponent(Args&&... args) {
            if (HasComponent<T>())
                HX_GAME_ERROR("Component already exists on entity with tag: {}", GetComponent<TagComponent>().tag);
            else
                return m_Scene->m_Registry.emplace<T>(m_Entity, std::forward<Args>(args)...);
        }
        template<typename T> bool HasComponent() {
            return m_Scene->m_Registry.all_of<T>(m_Entity);
        }
        template<typename T> T& GetComponent() {
            if (!HasComponent<T>())
                HX_GAME_ERROR("Component does not exist on entity with tag: {}", GetComponent<TagComponent>().tag);
            else
                return m_Scene->m_Registry.get<T>(m_Entity);
        }
        template<typename T> void RemoveComponent() {
            return m_Scene->m_Registry.remove<T>(m_Entity);
        }

        operator bool() const { return m_Scene->m_Registry.valid(m_Entity); }

    private:
        entt::entity m_Entity { 0 };
        Scene* m_Scene = nullptr;
    };

}

#endif