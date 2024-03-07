//
// Created by Andrew Graser on 3/7/2024.
//

#include "Application.h"

Application::Application() {
    mWindow = std::make_shared<Window>(WindowProps());
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

}

void Application::OnRender() {

}
