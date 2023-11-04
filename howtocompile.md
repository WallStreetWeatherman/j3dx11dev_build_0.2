g++ main_v0.1.0.cpp EngineCore_v0.2.1.cpp Renderer_v0.2.1.cpp MeshRenderer_v0.0.1.cpp Shader_v0.0.2.cpp -I"C:\Program Files (x86)\Windows Kits\10\Include\10.0.22000.0\um" -L"C:\Program Files (x86)\Windows Kits\10\Lib\10.0.22000.0\um\x64" -ld3d11 -lUser32 -o jade3dx11dev_prototype_build_0.2.exe

g++ jade3dx11_prototype/main_v0.1.0.cpp jade3dx11_prototype/EngineCore_v0.2.1.cpp jade3dx11_prototype/Renderer_v0.2.1.cpp jade3dx11_prototype/MeshRenderer_v0.0.1.cpp jade3dx11_prototype/Shader_v0.0.2.cpp -I"C:\Program Files (x86)\Windows Kits\10\Include\10.0.22000.0\um" -I"C:\Program Files (x86)\Windows Kits\10\Include\10.0.22000.0\shared" -L"C:\Program Files (x86)\Windows Kits\10\Lib\10.0.22000.0\um\x64" -ld3d11 -lUser32 -o jade3dx11dev_prototype.exe

g++ main_v0.1.0.cpp EngineCore_v0.2.1.cpp Renderer_v0.2.1.cpp MeshRenderer_v0.0.1.cpp Shader_v0.0.2.cpp -I"C:\Program Files (x86)\Windows Kits\10\Include\10.0.22000.0\um" -I"C:\Program Files (x86)\Windows Kits\10\Include\10.0.22000.0\shared" -L"C:\Program Files (x86)\Windows Kits\10\Lib\10.0.22000.0\um\x64" -ld3d11 -lUser32 -o jade3dx11dev_prototype.exe

cl /EHsc main_0.1.0.cpp EngineCore_v0.2.1.cpp MeshRenderer_v0.0.1.cpp Renderer_v0.2.1.cpp Shader_v0.0.1.cpp /link /out:jade3dx11dev_prototype_build_0.2.exe

g++ EngineCore_v0.2.1.cpp main_v0.1.0.cpp MeshRenderer_v0.0.1.cpp Renderer_v0.2.1.cpp Shader_v0.0.2.cpp -o GameEngine.exe -I"C:\Program Files (x86)\Windows Kits\10\Include\10.0.22000.0\um" -L"C:\Program Files (x86)\Windows Kits\10\Lib\10.0.22000.0\um\x64" -ld3d11


cl /EHsc EngineCore_v0.2.1.cpp main_0.1.0.cpp MeshRenderer_v0.0.1.cpp Renderer_v0.2.1.cpp Shader_v0.0.1.cpp /I "C:\Program Files (x86)\Windows Kits\10\Include\10.0.22000.0\um" /link /LIBPATH:"C:\Program Files (x86)\Windows Kits\10\Lib\10.0.22000.0\um\x64" d3d11.lib

g++ EngineCore_v0.2.1.cpp main_v0.1.0.cpp MeshRenderer_v0.0.1.cpp Renderer_v0.2.1.cpp Shader_v0.0.2.cpp -o GameEngine.exe -I"C:\Program Files (x86)\Windows Kits\10\Include\10.0.22000.0\um" -I"C:\Program Files (x86)\Windows Kits\10\Include\10.0.22000.0\shared" -L"C:\Program Files (x86)\Windows Kits\10\Lib\10.0.22000.0\um\x64" -ld3d11
