// EngineCore_v0.2.2.cpp
#include "EngineCore_v0.2.4.hpp"

EngineCore::EngineCore() {}

EngineCore::~EngineCore() {
    Shutdown();
}

bool EngineCore::Initialize(HINSTANCE hInstance, int nCmdShow, HWND hWnd) {
    renderer = std::make_unique<Renderer>(hWnd);
    return renderer->Initialize();
}

void EngineCore::Shutdown() {
    renderer->Shutdown();
}

void EngineCore::Render() {  // Retained for drawing
    renderer->Draw();
}