//
// Created by Andrew Graser on 3/7/2024.
//

#include "Application.h"
#include "Glad/glad.h"


Application* Application::sInstance = nullptr;

Application::Application() {
    sInstance = this;

    mWindow = std::make_shared<Window>(WindowProps());

    float squareVertices[3 * 3 * 2] = {
            -0.5f, -0.5f, 0.0f,         0.0f, 0.0f,
            0.5f, -0.5f, 0.0f,          1.0f, 0.0f,
            0.5f, 0.5f, 0.0f,        1.0f, 1.0f,
    };


    glGenVertexArrays(1, &mVA);
    glBindVertexArray(mVA);

    glGenBuffers(1, &mVB);
    glBindBuffer(GL_ARRAY_BUFFER, mVB);
    glBufferData(GL_ARRAY_BUFFER, sizeof(squareVertices), &squareVertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, nullptr);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)(sizeof(float)* 3));

    glDeleteBuffers(1, &mVB);
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
    glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Application::OnRender() {
    glBindVertexArray(mVA);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
