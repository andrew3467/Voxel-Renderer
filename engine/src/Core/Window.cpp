//
// Created by Andrew Graser on 3/7/2024.
//

#include <iostream>
#include "Window.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"

#include <GLFW/glfw3.h>
#include <Glad/glad.h>


static void GLFWErrorCallback(int error_code, const char* description){
    std::cerr << "GLFW Error: (" << error_code << ")" << description << "\n";
}

Window::Window(const WindowProps &props)
    : mData(props)
{
    Init();
}

Window::~Window() {

}

void Window::OnUpdate() {
    glfwPollEvents();
    glfwSwapBuffers(mWindow);
}

void Window::Init() {
    glfwSetErrorCallback(GLFWErrorCallback);

    if(!glfwInit()){
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
        auto& data = *(WindowProps*)glfwGetWindowUserPointer(window);

        WindowCloseEvent event;
        data.EventCallback(event);
    });

    glfwSetWindowSizeCallback(mWindow, [](GLFWwindow* window, int width, int height) {
        auto& data = *(WindowProps*)glfwGetWindowUserPointer(window);

        data.Width = width;
        data.Height = height;
        WindowResizeEvent event(width, height);
        data.EventCallback(event);
    });

    glfwSetKeyCallback(mWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
        auto& data = *(WindowProps*)glfwGetWindowUserPointer(window);

        switch (action) {
            case GLFW_PRESS: {
                KeyPressedEvent event(key, 0);
                data.EventCallback(event);
                break;
            }
            case GLFW_RELEASE: {
                KeyReleasedEvent event(key);
                data.EventCallback(event);
                break;
            }
            case GLFW_REPEAT: {
                KeyPressedEvent event(key, 1);
                data.EventCallback(event);
                break;
            }
        }
    });
}
