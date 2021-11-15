#pragma once

#include "Primis/Core/Core.hpp"

namespace Primis
{
    enum class EventType
    {
        None = 0,
        WindowResized, WindowMoved, WindowClose, WindowFocus, WindowLostFocus,
        KeyPressed, KeyReleased,
        AppTick, AppUpdate, AppRender,
        MouseMoved, MovedScrolled, MouseButtonPressed, MouseButtonReleased,
    };

    enum EventCategory
    {
        None = 0,
        EventCategoryApplication = BIN(0),
        EventCategoryInput = BIN(1),
        EventCategoryKeyboard = BIN(2),
        EventCategoryMouse = BIN(3),
        EventCategoryMouseButton = BIN(4),
    };

#define EVENT_CLASS_TYPE(type)                                                                                           \
    static EventType GetStaticType(){return EvenType::##type} EventType GetEventType() const { return GetStaticType(); } \
    const char *GetName() const { return ##type; };

#define EVENT_CLASS_CATEGORY(category) \
    virtual int GetCategoryFlags() const override { return category; }

    class Event
    {
        friend class EventDispatcher;

    public:
        virtual EventType GetEventType() const = 0;
        virtual const char *GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;
        virtual std::string ToString() const { return GetName(); }

        inline bool IsInCategory(EventCategory category){
            return GetCategoryFlags() & category};

    protected:
        bool m_Handled = false;
    };

    class EventDispatcher
    {
        template <typename T>
        using EventFn = std::function<bool(T &)>;

    public:
        template <typename T>
        bool Dispatch(EventFn<T> func)
        {
            if (m_Event.GetEventType() == T::GetStaticType())
            {
                m_Event.m_Handled = func(*(T *)&m_Event);
                return true;
            };
            return false;
        };

    private:
        Event &m_Event;
    };

    inline std::ostream &operator<<(std::ostream &os, const Event &e)
    {
        return os << e.ToString();
    };

}
