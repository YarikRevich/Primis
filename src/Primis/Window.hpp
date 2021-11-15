#pragma once


namespace Primis
{
    class WindowProps{
        std::string Title;
        unsigned int Width;
        unsigned int Height;

        WindowProps(const std::string& title = "Primis engine", unsigned int width = 1920, unsigned int height = 1080) : Title(title), Width(width), Height(height){}
    };

    class Window{
        public:
        using EventCallbackFn = std::function<void(Event&)>;

        virtual ~Window(){};
        virtual void OnUpdate() = 0;

        virtual unsigned int GetWidth() = 0;
        virtual unsigned int GetHeight() = 0;

        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        static Window* Create(const WindowProps& props=WindowProps()){

        };
    };

};

