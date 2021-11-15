#pragma once

#include "Event.hpp"

namespace Primis {
    class WindowResizeEvent : public Event{
        public:
            WindowResizeEvent(unsigned int width, height) : m_Width(width), m_Height(height) {};

            inline unsigned int GetWidth() const {return m_Width;};
            inline unsigned int GetHeight() const {return m_Height;};

            std::string ToString() const override{
                std::streamstring ss;
                ss << "Window resize event" << "(" << m_Width << ", " << m_Height << ")";
                return ss.str();
            };

            EVENT_CLASS_CATEGORY(EventCategoryApplication);

        private:
            unsigned int m_Width, m_Height;
    };


    class WindowCloseEvent : public Event{
        public:
            inline unsigned int GetWidth() const {return m_Width;};
            inline unsigned int GetHeight() const {return m_Height;};

            std::string ToString() const override{
                std::streamstring ss;
                ss << "Window resize event" << "(" << m_Width << ", " << m_Height << ")";
                return ss.str();
            };

            EVENT_CLASS_TYPE(EventCategory::WindowResize);
    };


};