#pragma once

#include "Core/Core.hpp"

namespace Primis {
    class Application{
        public: 
            Application();
            ~Application();

            void Run();
    };

    Application* CreateApplication();
};