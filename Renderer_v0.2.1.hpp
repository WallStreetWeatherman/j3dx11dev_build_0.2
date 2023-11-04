// Renderer_v0.2.1.hpp
#pragma once
#include <d3d11.h>
#include <memory>
#include "MeshRenderer_v0.0.1.hpp"
#include "Shader_v0.0.3.hpp"

class Renderer {
public:
    Renderer(HWND hWnd);
    ~Renderer();

    bool Initialize();
    void Draw();
    void Shutdown();

private:
    HWND hWnd;
    ID3D11Device* device;
    ID3D11DeviceContext* deviceContext;
    IDXGISwapChain* swapChain;
    ID3D11RenderTargetView* renderTargetView;
    ID3D11InputLayout* inputLayout;
    ID3D11ShaderResourceView* textureResourceView;
    ID3D11SamplerState* samplerState;

    std::unique_ptr<MeshRenderer> meshRenderer;
    std::unique_ptr<Shader> shader;
};
