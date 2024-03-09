//
// Created by Andrew Graser on 3/7/2024.
//

#ifndef VOXEL_RENDERER_WINDOW_H
#define VOXEL_RENDERER_WINDOW_H

#include <cstdint>
#include <string>
#include <functional>
#include "Events/Event.h"

class GLFWwindow;

class Window {
public:
    using EventCallbackFn = std::function<void(Event&)>;

    struct WindowProps {
        uint32_t Width = 1280;
        uint32_t Height = 720;
        std::string Title = "Voxel Renderer";

        EventCallbackFn EventCallback;
    };

    Window(const WindowProps &props);
    ~Window();

    void OnUpdate();

    inline void SetEventCallback(const EventCallbackFn &callback) {
        mData.EventCallback = callback;
    }

    inline uint32_t GetWidth() const {return mData.Width;}
    inline uint32_t GetHeight() const {return mData.Height;}

    inline GLFWwindow* GetNativeWindow() const {return mWindow;}

private:
    void Init();

    void SetupCallbacks();
private:
    GLFWwindow* mWindow;

    WindowProps mData;
};


#endif //VOXEL_RENDERER_WINDOW_H
