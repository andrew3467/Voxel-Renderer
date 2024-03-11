//
// Created by Andrew Graser on 3/8/2024.
//

#include "PerspectiveCameraController.h"
#include "Core/Input.h"

#include <GLFW/glfw3.h>


PerspectiveCameraController::PerspectiveCameraController(float moveSpeed, float sensitivity)
    :mMoveSpeed(moveSpeed), mSensitivity(sensitivity)
{
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
        mCamera->ProcessKeyboard(FORWARD, ts, mMoveSpeed);
    }
    if(Input::IsKeyPressed(GLFW_KEY_S)) {
        mCamera->ProcessKeyboard(BACKWARD, ts, mMoveSpeed);
    }
    if(Input::IsKeyPressed(GLFW_KEY_A)) {
        mCamera->ProcessKeyboard(LEFT, ts, mMoveSpeed);
    }
    if(Input::IsKeyPressed(GLFW_KEY_D)) {
        mCamera->ProcessKeyboard(RIGHT, ts, mMoveSpeed);
    }
}

void PerspectiveCameraController::MouseInput(float ts) {
    auto [x,y]  = Input::GetMousePos();

    if(mFirstMouse){
        mLastX = x;
        mLastY = y;

        mFirstMouse = false;
    }

    mCamera->ProcessMouseMovement(x - mLastX, y- mLastY, mSensitivity * ts);
}
