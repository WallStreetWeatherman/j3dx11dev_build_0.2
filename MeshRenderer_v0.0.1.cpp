// MeshRenderer_v0.0.1.cpp

#include "MeshRenderer_v0.0.1.hpp"

MeshRenderer::MeshRenderer() : vertexBuffer(nullptr), indexBuffer(nullptr) {}

MeshRenderer::~MeshRenderer() {
    if (vertexBuffer) vertexBuffer->Release();
    if (indexBuffer) indexBuffer->Release();
}

bool MeshRenderer::Initialize(ID3D11Device* device) {
    // Define vertices of a triangle
    float vertices[] = {
        // X   Y   Z
        0.0f, 1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        -1.0f, -1.0f, 0.0f
    };

    // Vertex buffer
    D3D11_BUFFER_DESC bd;
    ZeroMemory(&bd, sizeof(bd));
    bd.Usage = D3D11_USAGE_DYNAMIC;
    bd.ByteWidth = sizeof(float) * 9;
    bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

    D3D11_SUBRESOURCE_DATA sd;
    ZeroMemory(&sd, sizeof(sd));
    sd.pSysMem = vertices;

    if (FAILED(device->CreateBuffer(&bd, &sd, &vertexBuffer))) {
        return false;
    }

    return true;
}

void MeshRenderer::Render(ID3D11DeviceContext* deviceContext) {
    // Render the cube
    UINT stride = sizeof(float) * 3;
    UINT offset = 0;
    deviceContext->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);
    deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    deviceContext->Draw(3, 0);
}