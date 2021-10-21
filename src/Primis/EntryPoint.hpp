#pragma once

#ifndef __WIN32__
    extern Primis::Application* Primis::CreateApplication();

    int main(int argc, char** argv){
        Primis::Log::Init();

        PRIMIS_ERROR_LOG("IT WORKS!");

        auto app = Primis::CreateApplication();
        app->Run();
        delete app;
    };
#endif