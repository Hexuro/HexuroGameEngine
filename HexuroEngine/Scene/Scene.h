#ifndef _HEXURO_SCENE_
#define _HEXURO_SCENE_

#include "Components.h"
#include "entt/entt.hpp"

namespace Hexuro {
    class Entity;

    class Scene {
    public:
        Scene();
        ~Scene();

        Entity CreateEntity(const std::string name = std::string());

        void Update();

    private:
        entt::registry m_Registry;

        friend class Entity;
        friend class Renderer;
    };

}

#endif