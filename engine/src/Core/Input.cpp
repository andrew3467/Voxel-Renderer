//
// Created by Andrew Graser on 3/8/2024.
//

#include "Input.h"
#include "Application.h"
#include "GLFW/glfw3.h"

bool Input::IsKeyPressed(int keycode) {
    auto window = static_cast<GLFWwindow*>(Application::GetInstance().GetWindow().GetNativeWindow());
    auto state = glfwGetKey(window, keycode);
    return state == GLFW_PRESS || state == GLFW_REPEAT;
}

bool Input::IsMouseButtonPressed(int button) {
    auto window = static_cast<GLFWwindow*>(Application::GetInstance().GetWindow().GetNativeWindow());
    auto state = glfwGetMouseButton(window, button);
    return state == GLFW_PRESS;
}

float Input::GetMouseX() {
    auto[x, y] = GetMousePos();
    return x;
}

float Input::GetMouseY() {
    auto[x, y] = GetMousePos();
    return y;
}

std::pair<float, float> Input::GetMousePos() {
    auto window = static_cast<GLFWwindow*>(Application::GetInstance().GetWindow().GetNativeWindow());
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    return { xpos, ypos };
}

void Input::SetMousePos(float x, float y) {
    auto window = static_cast<GLFWwindow*>(Application::GetInstance().GetWindow().GetNativeWindow());
    glfwSetCursorPos(window, x, y);
}
