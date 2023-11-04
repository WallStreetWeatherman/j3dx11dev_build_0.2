// Renderer_v0.2.2.cpp

#include "Renderer_v0.2.1.hpp"  // You might want to change this to v0.2.2 to match the updated version
#pragma comment(lib, "d3d11.lib")
#include <d3d11.h>

Renderer::Renderer(HWND hWnd) : hWnd(hWnd), device(nullptr), deviceContext(nullptr), swapChain(nullptr), renderTargetView(nullptr), textureResourceView(nullptr), samplerState(nullptr) {
    meshRenderer = std::make_unique<MeshRenderer>();
    shader = std::make_unique<Shader>();
}

Renderer::~Renderer() {
    Shutdown();
}

bool Renderer::Initialize() {
    DXGI_SWAP_CHAIN_DESC scd;
    ZeroMemory(&scd, sizeof(DXGI_SWAP_CHAIN_DESC));

    scd.BufferCount = 1;
    scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    scd.BufferDesc.Width = 800;
    scd.BufferDesc.Height = 600;
    scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    scd.OutputWindow = hWnd;
    scd.SampleDesc.Count = 1;
    scd.Windowed = TRUE;

    HRESULT hr = D3D11CreateDeviceAndSwapChain(
        nullptr,
        D3D_DRIVER_TYPE_HARDWARE,
        nullptr,
        0,
        nullptr,
        0,
        D3D11_SDK_VERSION,
        &scd,
        &swapChain,
        &device,
        nullptr,
        &deviceContext
    );

    ID3D11Texture2D* pBackBuffer;
    swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
    device->CreateRenderTargetView(pBackBuffer, nullptr, &renderTargetView);
    pBackBuffer->Release();
    deviceContext->OMSetRenderTargets(1, &renderTargetView, nullptr);

    if (!meshRenderer->Initialize(device)) {
        return false;
    }

    if (!shader->Initialize(device)) {
        return false;
    }

    // Additions start here
    ID3DBlob* vsBlob = shader->GetVertexShaderBlob();
    void* shaderByteCode = vsBlob->GetBufferPointer();
    size_t byteCodeLength = vsBlob->GetBufferSize();
    // Additions end here

    D3D11_INPUT_ELEMENT_DESC layoutDesc[] = {
        {"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0},
    };

    if (FAILED(device->CreateInputLayout(layoutDesc, 1, shaderByteCode, byteCodeLength, &inputLayout))) {
        return false;
    }

    return true;
}

void Renderer::Draw() {
    float clearColor[4] = { 0.0f, 0.2f, 0.4f, 1.0f };
    deviceContext->ClearRenderTargetView(renderTargetView, clearColor);

    deviceContext->IASetInputLayout(inputLayout);

    shader->Apply(deviceContext);

    meshRenderer->Render(deviceContext);

    swapChain->Present(0, 0);
}

void Renderer::Shutdown() {
    if (renderTargetView) renderTargetView->Release();
    if (swapChain) swapChain->Release();
    if (deviceContext) deviceContext->Release();
    if (device) device->Release();
    if (inputLayout) inputLayout->Release();
    if (textureResourceView) textureResourceView->Release();
    if (samplerState) samplerState->Release();
}
