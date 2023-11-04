// Shader_v0.0.3.hpp

#pragma once
#include <d3d11.h>

class Shader {
public:
    Shader();
    ~Shader();

    bool Initialize(ID3D11Device* device);
    void Apply(ID3D11DeviceContext* deviceContext);
    ID3DBlob* GetVertexShaderBlob() const { return vsBlob; }

private:
    ID3D11VertexShader* vertexShader;
    ID3D11PixelShader* pixelShader;
    ID3DBlob* vsBlob;
    ID3DBlob* psBlob;  // Added this line
};