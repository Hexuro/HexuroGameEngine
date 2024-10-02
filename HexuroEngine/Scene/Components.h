#ifndef _HEXURO_COMPONENTS_
#define _HEXURO_COMPONENTS_

#include "Core/Utils.h"
#include "../Renderer/Color.h"
#include <string>

namespace Hexuro {
    struct TransformComponent {
        Vector3 position;
        Vector3 rotation;
        Vector3 scale;

        TransformComponent() = default;
        TransformComponent(const TransformComponent&) = default;
    };

    struct TagComponent {
        std::string tag;

        TagComponent() : tag("") {}
        TagComponent(const TagComponent&) = default;
        TagComponent(const std::string& rhs)
            : tag(rhs) {}

        operator const std::string() const { return tag; }
        operator std::string() { return tag; }
    };

    struct SpriteComponent {
        Color color;
    };
}

#endif // !_HEXURO_COMPONENTS_