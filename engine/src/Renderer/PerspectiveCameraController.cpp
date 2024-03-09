//
// Created by Andrew Graser on 3/8/2024.
//

#include "PerspectiveCameraController.h"
#include "Core/Input.h"

#include <GLFW/glfw3.h>


PerspectiveCameraController::PerspectiveCameraController() {
    mCamera = std::make_shared<PerspectiveCamera>(glm::vec3(0.0f, 0.0f, 3.0f), 1280.0f/720.0f);
}

PerspectiveCameraController::~PerspectiveCameraController() {

}

void PerspectiveCameraController::ProcessInput(float ts) {
    KeyboardInput(ts);
    MouseInput(ts);
}

void PerspectiveCameraController::KeyboardInput(float ts) {
    if(Input::IsKeyPressed(GLFW_KEY_W)) {
        mCamera->ProcessKeyboard(FORWARD, ts);
    }
}

void PerspectiveCameraController::MouseInput(float ts) {

}
