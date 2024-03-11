//
// Created by Andrew Graser on 3/8/2024.
//

#ifndef VOXEL_RENDERER_PERSPECTIVECAMERA_H
#define VOXEL_RENDERER_PERSPECTIVECAMERA_H

#include "glm/glm.hpp"


enum Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

class PerspectiveCamera {
public:
    PerspectiveCamera();
    PerspectiveCamera(const glm::vec3 &position, float aspect);
    ~PerspectiveCamera();

    void SetPosition(const glm::vec3 &position) {mPosition = position; RecalculateMatrices();}
    void SetRotation(const glm::vec3 &rotation);

    void ProcessKeyboard(Camera_Movement direction, float deltaTime, float moveSpeed);
    void ProcessMouseMovement(float xoffset, float yoffset,  float sensitivity, bool constrainPitch = true);
    void ProcessMouseScroll(float yoffset);

    inline const glm::mat4& GetViewProjection() const {return mViewProjection;}
    inline const glm::mat4& GetView() const {return mView;}
    inline const glm::mat4& GetProjection() const {return mProjection;}

private:
    void RecalculateMatrices();

private:
    glm::mat4 mView;
    glm::mat4 mProjection;
    glm::mat4 mViewProjection;

    glm::vec3 mPosition;
    glm::vec3 mFront = {0.0f, 0.0f, 1.0f};
    glm::vec3 mUp = {0.0f, 1.0f, 0.0f};
    glm::vec3 mRight = {1.0f, 0.0f, 0.0f};
    glm::vec3 mWorldUp = {0.0f, 1.0f, 0.0f};

    float mFOV = 60.0f;
    float mAspect;
    float mNear, mFar;

    float mYaw = -90.0f;
    float mPitch = 0.0f;
};


#endif //VOXEL_RENDERER_PERSPECTIVECAMERA_H
