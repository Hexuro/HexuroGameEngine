#ifndef _HEXURO_KEYEVENT_
#define _HEXURO_KEYEVENT_

#include <sstream>
#include "Event.h"
#include "pch.h" // Intellisense being weird

namespace Hexuro {
    class KeyEvent : public Event {
    public:
        inline int GetKeyCode() const { return m_KeyCode; }

        EVENT_CLASS_CATEGORY(EKeyboard | EInput)

    protected:
        KeyEvent(int keyCode) : m_KeyCode(keyCode) {}

        int m_KeyCode;
    };

    class KeyPressedEvent : public KeyEvent {
    public:
        KeyPressedEvent(int keyCode, int repeatCount = 0): KeyEvent(keyCode), m_RepeatCount(repeatCount) {}
        inline int GetRepeatCount() const { return m_RepeatCount; }
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << static_cast<int>(m_KeyCode) << " (repeat = " << m_RepeatCount << ")";
            return ss.str();
        }
        EVENT_CLASS_TYPE(KeyPressed)

    private:
        int m_RepeatCount;
    };

    class KeyReleasedEvent : public KeyEvent {
    public:
        KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_KeyCode;
            return ss.str();
        }
        EVENT_CLASS_TYPE(KeyReleased)
    };
}

#endif