//
// Created by Andrew Graser on 3/8/2024.
//

#include "Renderer.h"
#include "glm/ext/matrix_transform.hpp"

#include <Glad/glad.h>

struct RendererData {
    uint32_t SquareVertexArray;

    std::shared_ptr<Shader> Shader;
};

RendererData *sData;


void Renderer::Init() {
    sData = new RendererData();


    {
        float squareVertices[6 * 5] = {
                -0.5f, -0.5f, 0.0f,              0.0f, 0.0f,
                -0.5f, 0.5f, 0.0f,               0.0f, 1.0f,
                0.5f, 0.5f, 0.0f,             1.0f, 1.0f,

                0.5f, 0.5f, 0.0f,              1.0f, 1.0f,
                0.5f, -0.5f, 0.0f,               1.0f, 0.0f,
                -0.5f, -0.5f, 0.0f,             0.0f, 0.0f,
        };


        glGenVertexArrays(1, &sData->SquareVertexArray);
        glBindVertexArray(sData->SquareVertexArray);

        uint32_t VB;
        glGenBuffers(1, &VB);
        glBindBuffer(GL_ARRAY_BUFFER, VB);
        glBufferData(GL_ARRAY_BUFFER, sizeof(squareVertices), squareVertices, GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)0);

        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)(sizeof(float)* 3));
    }


    sData->Shader = std::make_shared<Shader>("../assets/shaders/Solid_Unlit.glsl");
}

void Renderer::SetClearColor(glm::vec3 color) {
    glEnable(GL_DEPTH_TEST);
    glClearColor(color.x, color.y, color.z, 1.0f);
}

void Renderer::Clear() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::DrawSquare(const glm::vec3 &position, const glm::vec3 &scale, const glm::vec3 &color) {
    auto transform = glm::translate(glm::mat4(1.0f), position) *
            glm::scale(glm::mat4(1.0f), scale);

    sData->Shader->Bind();
    sData->Shader->SetFloat3("uColor", color);
    sData->Shader->SetMat4("uTransform", transform);


    glBindVertexArray(sData->SquareVertexArray);
    glDrawArrays(GL_TRIANGLES, 0, 6);
}

void Renderer::StartScene(const PerspectiveCamera &camera) {
    sData->Shader->Bind();
    sData->Shader->SetMat4("uViewProj", camera.GetViewProjection());
}

void Renderer::OnWindowResize(unsigned int width, unsigned int height) {
    glViewport(0, 0, width, height);
}
