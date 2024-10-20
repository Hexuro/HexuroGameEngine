#ifndef _HEXURO_EVENT_
#define _HEXURO_EVENT_

#include "Core/Core.h"
#include <string>
#include <functional>

namespace Hexuro {
    enum class EventType {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
        KeyPressed, KeyReleased,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    enum EventCategory {
        None = 0,
        Application = BIT(0),
        Input       = BIT(1),
        Keyboard    = BIT(2),
        Mouse       = BIT(3),
        MouseButton = BIT(4)
    };

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

    class Event {
    public:
        virtual const char* GetName() const = 0;
        virtual std::string ToString() const { return GetName(); }

        virtual EventType GetEventType() const = 0;
        virtual int GetCategoryFlags() const = 0;
        bool IsInCategory(EventCategory category) { return GetCategoryFlags() & category; }

        //void SetHandled(bool handled = true) { m_Handled = handled; }
        bool IsHandled() const { return m_Handled; }

    private:
        bool m_Handled = false;

        friend class EventDispatcher;
    };

    class EventDispatcher {
        template<typename T>
        using EventFn = std::function<bool(T&)>;

    public:
        EventDispatcher(Event& event) : m_Event(event) {}

        template<typename T>
        bool Dispatch(EventFn<T> func)
        {
            if (m_Event.GetEventType() == T::GetStaticType())
            {
                m_Event.m_Handled = func(*(T*)&m_Event);
                return true;
            }
            return false;
        }
    private:
        Event& m_Event;
    };

    inline std::ostream& operator << (std::ostream os, Event& e) {  return os << e.ToString(); }

}

#endif