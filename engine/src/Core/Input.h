//
// Created by Andrew Graser on 3/8/2024.
//

#ifndef VOXEL_RENDERER_INPUT_H
#define VOXEL_RENDERER_INPUT_H


#include <utility>

class Input {
public:
    static bool IsKeyPressed(int keycode);
    static bool IsMouseButtonPressed(int button);

    static float GetMouseX();
    static float GetMouseY();
    static void SetMousePos(float x, float y);
    static std::pair<float, float> GetMousePos();
};


#endif //VOXEL_RENDERER_INPUT_H
