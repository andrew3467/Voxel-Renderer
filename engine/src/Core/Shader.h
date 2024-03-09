//
// Created by Andrew Graser on 3/7/2024.
//

#ifndef VOXEL_RENDERER_SHADER_H
#define VOXEL_RENDERER_SHADER_H


#include <cstdint>
#include <string>
#include "glm/glm.hpp"

class Shader {
public:
    Shader(const std::string& path);
    ~Shader();

    void Bind();
    void Unbind();

    int GetLocation(const std::string& name);

    void SetInt(const std::string& name, int v);
    void SetInt2(const std::string& name, const glm::ivec2& v);
    void SetInt3(const std::string& name, const glm::ivec3& v);
    void SetInt4(const std::string& name, const glm::ivec4& v);

    void SetFloat(const std::string& name, float v);
    void SetFloat2(const std::string& name, const glm::vec2& v);
    void SetFloat3(const std::string& name, const glm::vec3& v);
    void SetFloat4(const std::string& name, const glm::vec4& v);

    void SetMat3(const std::string& name, const glm::mat3& v);
    void SetMat4(const std::string& name, const glm::mat4& v);
    
private:
    uint32_t mRendererID;
};


#endif //VOXEL_RENDERER_SHADER_H
