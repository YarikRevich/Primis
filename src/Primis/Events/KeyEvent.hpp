#pragma once

#include "Event.hpp"
#include "Primis/Core/KeyCodes.hpp"

namespace Primis
{
    class KeyEvent : public Event
    {
    public:
        inline int GetKeyCode() { return m_KeyCode; };

        KeyEvent(int keycode) : m_KeyCode(keycode){};

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput);
        int m_KeyCode;
    };

    class KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(const KeyCode keycode, const uint16_t repeatCount) : KeyEvent(keycode), m_RepeatCount(repeatCount){};

        uint16_t GetRepeatCount() const { return m_RepeatCount; };
        std::string ToString() const override { 
            std::stringstream ss;
            ss << "KeyPressed event" << m_KeyCode << "(" << m_RepeatCount << ")";
            return ss.str();
         };

        EVENT_CLASS_TYPE(EventType::KeyPressed);

    private:
        uint16_t m_RepeatCount;
    };
    class KeyReleasedEvent : public KeyEvent
    {
    public:
        std::string ToString() const override { return ""; };
    };
    class KeyTypedEvent : public KeyEvent
    {
    public:
        std::string ToString() const override { return ""; };
    };
};