//
// Created by Andrew Graser on 3/13/2024.
//

#ifndef VOXEL_RENDERER_BLOKC_H
#define VOXEL_RENDERER_BLOKC_H

#include "glm/vec3.hpp"

typedef glm::vec3 VoxelPos;

class Voxel {
public:
    Voxel(VoxelPos pos, bool isTransparent = false);
    Voxel();
    ~Voxel();

    bool IsTransparent() const {return mIsTransparent;}
    bool IsOpaque() const {return !mIsTransparent;}

    VoxelPos GetPosition() const {return mPosition;}

private:
    VoxelPos mPosition;
    short mType;

    bool mIsTransparent;
};


#endif //VOXEL_RENDERER_BLOKC_H
