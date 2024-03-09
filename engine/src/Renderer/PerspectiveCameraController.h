//
// Created by Andrew Graser on 3/8/2024.
//

#ifndef VOXEL_RENDERER_PERSPECTIVECAMERACONTROLLER_H
#define VOXEL_RENDERER_PERSPECTIVECAMERACONTROLLER_H


#include <memory>
#include "PerspectiveCamera.h"

#include <GLFW/glfw3.h>

class PerspectiveCameraController {
public:
    PerspectiveCameraController();
    ~PerspectiveCameraController();

    inline PerspectiveCamera& GetCamera() const {return *mCamera;}

    void ProcessInput(float ts);

private:
    void KeyboardInput(float ts);
    void MouseInput(float ts);

private:
    std::shared_ptr<PerspectiveCamera> mCamera;
};


#endif //VOXEL_RENDERER_PERSPECTIVECAMERACONTROLLER_H
