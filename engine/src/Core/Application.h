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

    inline static Application& GetInstance() {return *sInstance;}

    inline void StartClose() {mRunning = false;}
    void Run();


    void OnUpdate();
    void OnRender();


private:
    static Application* sInstance;

    bool mRunning = true;

    std::shared_ptr<Window> mWindow;

    uint32_t mVA, mVB;

};


#endif //VOXEL_RENDERER_APPLICATION_H
