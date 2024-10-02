#ifndef _HEXURO_LAYER_
#define _HEXURO_LAYER_

#include "Timestep.h"

namespace Hexuro {
    class Layer {
    public:
        Layer(const std::string& name = "Unnamed layer") : m_Name(name) {}
        virtual ~Layer() = default;

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
        virtual void OnUpdate(Timestep ts) {}
        virtual void OnRender() {}

        const std::string& GetName() const { return m_Name; }
    protected:
        std::string m_Name;
    };

}

#endif
