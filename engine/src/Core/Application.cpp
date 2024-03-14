//
// Created by Andrew Graser on 3/7/2024.
//

#include <iostream>
#include "Application.h"
#include "Glad/glad.h"
#include "Renderer/Renderer.h"
#include "Events/ApplicationEvent.h"
#include "Core/Input.h"


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

bool sWireFrameMode = false;

Application::Application() {
    sInstance = this;

    mWindow = std::make_shared<Window>(Window::WindowProps());
    mWindow->SetEventCallback(BIND_EVENT_FUNC(Application::OnEvent));

    mCameraController = std::make_shared<PerspectiveCameraController>(10.0f, 20.0f);

    Renderer::Init();

    mLevel.CreateChunks();
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
    float time = (float)glfwGetTime();
    mDeltaTime = time - mLastFrame;
    mLastFrame = time;

    mCameraController->ProcessInput(mDeltaTime);

    if(Input::IsKeyPressed(GLFW_KEY_SPACE)){
        sWireFrameMode = !sWireFrameMode;
        glPolygonMode(GL_FRONT_AND_BACK,
                      sWireFrameMode ? GL_LINE : GL_FILL
                      );
    }
}

void Application::OnRender() {
    Renderer::SetClearColor({0.2f, 0.2f, 0.2f});
    Renderer::Clear();

    Renderer::StartScene(mCameraController->GetCamera());

    mLevel.RenderChunks();
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
