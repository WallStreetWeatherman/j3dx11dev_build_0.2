// Shader_v0.0.5.cpp

#include "Shader_v0.0.3.hpp"
#include <D3DCompiler.h>

// Initialized vsBlob and psBlob to nullptr
Shader::Shader() : vertexShader(nullptr), pixelShader(nullptr), vsBlob(nullptr), psBlob(nullptr) {}

Shader::~Shader() {
    if (vertexShader) vertexShader->Release();
    if (pixelShader) pixelShader->Release();
    if (vsBlob) vsBlob->Release();
    if (psBlob) psBlob->Release();  // Added this line
}

bool Shader::Initialize(ID3D11Device* device) {
    const char* vsCode = "...";
    const char* psCode = "...";

    ID3DBlob* errorBlob = nullptr;

    if (FAILED(D3DCompile(vsCode, strlen(vsCode), nullptr, nullptr, nullptr, "main", "vs_5_0", 0, 0, &vsBlob, &errorBlob))) {
        if (errorBlob) {
            errorBlob->Release();
        }
        return false;
    }

    if (FAILED(device->CreateVertexShader(vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(), nullptr, &vertexShader))) {
        vsBlob->Release();
        return false;
    }

    // Compile and create pixel shader
    if (FAILED(D3DCompile(psCode, strlen(psCode), nullptr, nullptr, nullptr, "main", "ps_5_0", 0, 0, &psBlob, &errorBlob))) {
        if (errorBlob) {
            errorBlob->Release();
        }
        vsBlob->Release();
        return false;
    }

    if (FAILED(device->CreatePixelShader(psBlob->GetBufferPointer(), psBlob->GetBufferSize(), nullptr, &pixelShader))) {
        vsBlob->Release();
        psBlob->Release();
        return false;
    }

    if (psBlob) psBlob->Release();

    return true;
}

void Shader::Apply(ID3D11DeviceContext* deviceContext) {
    deviceContext->VSSetShader(vertexShader, nullptr, 0);
    deviceContext->PSSetShader(pixelShader, nullptr, 0);
}