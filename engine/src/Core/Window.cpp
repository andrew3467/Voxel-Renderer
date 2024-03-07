//
// Created by Andrew Graser on 3/7/2024.
//

#include <iostream>
#include "Window.h"
#include "GLFW/glfw3.h"

bool sGLFWInitialized = false;

Window::Window(const WindowProps &props)
    : mData(props)
{

}

Window::~Window() {

}

void Window::OnUpdate() {

}

void Window::Init() {
    if(!sGLFWInitialized){
        int success = glfwInit();

        if(!success){
            std::cerr << "Error: Failed to initialize GLFW!\n";
        }

        sGLFWInitialized = true;
    }

    
}