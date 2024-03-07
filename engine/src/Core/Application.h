//
// Created by Andrew Graser on 3/7/2024.
//

#ifndef VOXEL_RENDERER_APPLICATION_H
#define VOXEL_RENDERER_APPLICATION_H


#include <memory>
#include "Window.h"

class Application {
public:
    Application();
    ~Application();

    inline Application& GetInstance() {return *sInstance;}

    void Run();


    void OnUpdate();
    void OnRender();


private:
    Application* sInstance;

    bool mRunning = true;

    std::shared_ptr<Window> mWindow;

};


#endif //VOXEL_RENDERER_APPLICATION_H
