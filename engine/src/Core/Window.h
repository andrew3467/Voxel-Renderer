//
// Created by Andrew Graser on 3/7/2024.
//

#ifndef VOXEL_RENDERER_WINDOW_H
#define VOXEL_RENDERER_WINDOW_H

#include <cstdint>
#include <string>

class GLFWwindow;

struct WindowProps {
    uint32_t Width = 1280;
    uint32_t Height = 720;
    std::string Title = "Voxel Renderer";
};

class Window {
public:
    Window(const WindowProps &props);
    ~Window();

    void OnUpdate();

private:
    void Init();

private:
    GLFWwindow* mWindow;

    WindowProps mData;
};


#endif //VOXEL_RENDERER_WINDOW_H
