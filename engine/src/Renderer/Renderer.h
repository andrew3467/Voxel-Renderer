//
// Created by Andrew Graser on 3/8/2024.
//

#ifndef VOXEL_RENDERER_RENDERER_H
#define VOXEL_RENDERER_RENDERER_H


#include <memory>
#include "glm/vec3.hpp"
#include "Core/Shader.h"
#include "PerspectiveCamera.h"

class Renderer {
public:
    static void Init();

    static void SetClearColor(glm::vec3 color);
    static void Clear();

    static void StartScene(const PerspectiveCamera &camera);

    static void DrawSquare(const glm::vec3 &position, const glm::vec3 &scale, const glm::vec3 &color);
    static void DrawSquare(const glm::vec3 &color, const glm::mat4& transform);

    static void DrawCube(const glm::vec3 &position, const glm::vec3 &scale, const glm::vec3 &color);

    static void Submit(uint32_t vertexArray, uint32_t count, const glm::vec3 &color, const glm::mat4& transform);

    static void OnWindowResize(unsigned int width, unsigned int height);
};


#endif //VOXEL_RENDERER_RENDERER_H
