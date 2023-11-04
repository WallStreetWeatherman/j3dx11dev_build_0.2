// main_v0.1.1.cpp

#include <windows.h>
#include "EngineCore_v0.2.2.hpp"

// Your existing WndProc function remains the same
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProc(hWnd, message, wParam, lParam);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow) {
    // Register the window class.
    const wchar_t CLASS_NAME[] = L"Sample Window Class";
    
    WNDCLASS wc = { };
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create the window.
    HWND hWnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"Learn to Program Windows",    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style
        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
    );

    ShowWindow(hWnd, nCmdShow);

    // Initialize your engine
    EngineCore engine;
    if (!engine.Initialize(hInstance, nCmdShow, hWnd)) {  // Pass hWnd here
        return 1; // Initialization failed
    }

    // Main message loop
    MSG msg = { };
    ZeroMemory(&msg, sizeof(MSG));

    while (true) {  // This line replaces your previous 'while (GetMessage(...))'
        // Non-blocking message retrieval
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) {
                // Shutdown your engine
                engine.Shutdown();
                return 0;
            }

            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        // Continue with game logic and rendering here
        // For example:
        engine.Update();  // Assuming you have an Update method
        engine.Render();  // Assuming you have a Render method
    }

    // Shouldn't really get here
    return 0;
}