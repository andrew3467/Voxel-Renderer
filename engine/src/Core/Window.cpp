//
// Created by Andrew Graser on 3/7/2024.
//

#include <iostream>
#include "Window.h"
#include "GLFW/glfw3.h"
#include "Glad/glad.h"
#include "Application.h"


static void GLFWErrorCallback(int error_code, const char* description){
    std::cerr << "GLFW Error: (" << error_code << ")" << description << "\n";
}

Window::Window(const WindowProps &props)
    : mData(props)
{
    Init();
}

Window::~Window() {
    glfwDestroyWindow(mWindow);
    glfwTerminate();
}

void Window::OnUpdate() {
    glfwPollEvents();
    glfwSwapBuffers(mWindow);
}

void Window::Init() {
    glfwSetErrorCallback(GLFWErrorCallback);

    int success = glfwInit();

    if(!success){
        std::cerr << "Error: Failed to initialize GLFW!\n";
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    mWindow = glfwCreateWindow(mData.Width, mData.Height, mData.Title.c_str(), nullptr, nullptr);
    if(!mWindow){
        std::cerr << "Error: Failed to create GLFW window!\n";
    }

    glfwSetWindowUserPointer(mWindow, &mData);

    glfwMakeContextCurrent(mWindow);

    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)){
        std::cerr << "Error: Failed to initialize GLAD!\n";
    }

    SetupCallbacks();
}

void Window::SetupCallbacks() {
    glfwSetWindowCloseCallback(mWindow, [](GLFWwindow* window) {
        Application::GetInstance().StartClose();
    });
}
