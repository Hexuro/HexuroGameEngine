#include "pch.hpp"

#include "Application.h"

namespace Hexuro {

    int Application::Run()
    {
        if (Init())
            HX_ENGINE_FATAL("Could not initialize the application");
        HX_ENGINE_INFO("Succesfully initialized the application");

        while (!m_Window.ShouldClose())
        {
            m_Window.Update();
        }

        return 0;
    }

    int Application::Init()
    {
        m_Window.Init(600, 600, "Hello, window!");
        return 0;
    }
}