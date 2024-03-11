//
// Created by Andrew Graser on 3/7/2024.
//

#include <iostream>
#include "Application.h"
#include "Glad/glad.h"
#include "Renderer/Renderer.h"
#include "Events/ApplicationEvent.h"


static void GLClearError() {
    while(glGetError() != GL_NO_ERROR){

    }
}

static void GLCheckError() {
    while (GLenum error = glGetError()) {
        std::cerr << "[OpenGL Error]: (" << error << ")\n";
    }
}

#define BIND_EVENT_FUNC(x) std::bind(&x, this, std::placeholders::_1)


Application* Application::sInstance = nullptr;

Application::Application() {
    sInstance = this;

    mWindow = std::make_shared<Window>(Window::WindowProps());
    mWindow->SetEventCallback(BIND_EVENT_FUNC(Application::OnEvent));

    mCameraController = std::make_shared<PerspectiveCameraController>(0.5f, 0.25f);

    Renderer::Init();
}



Application::~Application() {

}

void Application::Run() {
    while (mRunning){
        mWindow->OnUpdate();

        OnUpdate();
        OnRender();
    }
}

void Application::OnUpdate() {
    mCameraController->ProcessInput(1);
}

void Application::OnRender() {
    Renderer::SetClearColor({0.2f, 0.2f, 0.2f});
    Renderer::Clear();

    Renderer::StartScene(mCameraController->GetCamera());

    Renderer::DrawSquare(glm::vec3(0.0f), glm::vec3(1.0f), glm::vec3(0.2f, 0.3f, 0.8f));
    Renderer::DrawSquare(glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.5f), glm::vec3(0.3f, 0.8f, 0.2f));
}

void Application::OnEvent(Event &e) {
    EventDispatcher dispatcher(e);
    dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FUNC(Application::OnWindowClosed));
    dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FUNC(Application::OnWindowResize));
}

bool Application::OnWindowClosed(WindowCloseEvent &e) {
    mRunning = false;

    return true;
}

bool Application::OnWindowResize(WindowResizeEvent &e) {
    Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());

    return true;
}
