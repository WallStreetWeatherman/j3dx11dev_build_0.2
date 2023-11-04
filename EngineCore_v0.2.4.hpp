// File: EngineCore_v0.2.4.hpp
// Version: 0.2.4
// Description: The core functionalities for the engine.

#pragma once
#include <windows.h>
#include "Renderer_v0.2.1.hpp"
#include <memory>  // for std::unique_ptr

class EngineCore {
public:
    EngineCore();
    ~EngineCore();

    bool Initialize(HINSTANCE hInstance, int nCmdShow, HWND hWnd);
    void Shutdown();
    void Render();  // Retained for drawing

private:
    std::unique_ptr<Renderer> renderer;
};