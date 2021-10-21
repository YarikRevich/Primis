#pragma once

namespace Primis {
    class Application{
        public: 
            Application();
            ~Application();

            void Run();
    };

    Application* CreateApplication();
};