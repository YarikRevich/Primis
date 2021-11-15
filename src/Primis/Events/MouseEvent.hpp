#pragma once

#include "Event.hpp"
#include "Primis/Core/MouseCodes.hpp"

namespace Primis
{
    class MouseMovedEvent : public Event
    {
    public:
        MouseMovedEvent(double mousex, double mousey) : m_MouseX(mousex), m_MouseY(mousey){};

        inline double GetMouseY() const { return m_MouseY; };
        inline double GetMouseX() const { return m_MouseX; };

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "Mouse moved event: " << m_MouseX << ", " << m_MouseY;
            return ss.str();
        };

        EVENT_CLASS_TYPE(MouseMoved);
        EVENT_CLASS_CATEGORY(EventCategoryMouse);

    private:
        double m_MouseX, m_MouseY;
    };

    class MouseScrolledEvent : public Event
    {

    public:
        MouseScrolledEvent(double offsetx, double offsety) : m_OffsetX(offsetx), m_OffsetY(offsety){};

        inline double GetOffsetX() const { return m_OffsetX; };
        inline double GetOffsetY() const { return m_OffsetY; };

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "Mouse scrolled event: " << m_OffsetX << ", " << m_OffsetY;
            return ss.str();
        };

        EVENT_CLASS_TYPE(MouseScrolled);
        EVENT_CLASS_CATEGORY(EventCategoryMouse);

    private:
        double m_OffsetX, m_OffsetY;
    };

    class MouseButtonEvent : public Event
    {

    public:
        MouseCode GetMouseButton() const { return m_Button; };

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput | EventCategoryMouseButton);

    protected:
        MouseButtonEvent(const MouseCode button) : m_Button(button){};

        MouseCode m_Button;
    };

    class MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonPressedEvent(const MouseCode button) : MouseButtonEvent(button) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << m_Button;
            return ss.str();
        };

        EVENT_CLASS_TYPE(MouseButtonPressed);
    };

    class MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonReleasedEvent(const MouseCode button) : MouseButtonEvent(button) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << m_Button;
            return ss.str();
        };

        EVENT_CLASS_TYPE(MouseButtonReleased);
    };
};