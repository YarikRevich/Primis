#pragma once

#include "Primis/Window.hpp"

#include <GLFW/glfw3.h>

namespace Primis{
    // static void GLFWErrorCallback(int error, const char* description);
    class MacOSWindow : public Window{
        public:
            MacOSWindow(const WindowProps& props);
            virtual ~MacOSWindow();

            void OnUpdate() override;

            inline unsigned int GetWidth() const override {return m_Data.Width;};
            inline unsigned int GetHeight() const override {return m_Data.Height;};

            void SetEventCallback(const EventCallbackFn& callback) override {m_Data.EventCallback = callback};
            void SetVSync(bool enabled) override;
            bool IsVSync() const override;

            inline virtual void* GetNativeWindow() const {return m_Window}; 
        private:
            virtual void Init(const WindowProps& props);
            virtual void Shutdown();

            GLFWwindow* m_Window;
            // Scope<>

            struct WindowData{
                std::string Title;
                unsigned int Width, Height;
                bool VSync;

                EventCallbackFn EventCallback;
            };

            WindowData m_Data;
    };
};