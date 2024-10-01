#ifndef _HEXURO_LAYER_
#define _HEXURO_LAYER_

namespace Hexuro {
    class Layer {
    public:
        Layer(const std::string& name = "Unnamed layer");
        virtual ~Layer() = default;

        void OnAttach() {}
        void OnDetach() {}
        //void OnUpdate(Timestep ts) {}
        //void OnEvent(Event& event) {}

        const std::string& GetName() const { return m_Name; }
    protected:
        std::string m_Name;
    };

}

#endif
