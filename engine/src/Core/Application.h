//
// Created by Andrew Graser on 3/7/2024.
//

#ifndef VOXEL_RENDERER_APPLICATION_H
#define VOXEL_RENDERER_APPLICATION_H


#include <memory>
#include "Window.h"
#include "Shader.h"
#include "Renderer/PerspectiveCameraController.h"
#include "Events/ApplicationEvent.h"

class Application {
public:
    Application();
    ~Application();

    inline static Application& GetInstance() {return *sInstance;}

    inline void StartClose() {mRunning = false;}
    inline Window GetWindow() {return *mWindow;}

    void Run();


    void OnUpdate();
    void OnRender();
    void OnEvent(Event &e);


private:
    static Application* sInstance;

    bool mRunning = true;

    std::shared_ptr<Window> mWindow;

    std::shared_ptr<PerspectiveCameraController> mCameraController;

    //TODO: Move into separate class
    float mLastFrame = 0.0f;
    float mDeltaTime = 0.0f;

    bool OnWindowClosed(WindowCloseEvent &e);
    bool OnWindowResize(WindowResizeEvent &e);
};


#endif //VOXEL_RENDERER_APPLICATION_H
