// MeshRenderer_v0.0.1.hpp
#pragma once
#include <d3d11.h>

class MeshRenderer {
public:
    MeshRenderer();
    ~MeshRenderer();

    bool Initialize(ID3D11Device* device);
    void Render(ID3D11DeviceContext* deviceContext);

private:
    ID3D11Buffer* vertexBuffer;
    ID3D11Buffer* indexBuffer;
};