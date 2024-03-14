//
// Created by Andrew Graser on 3/13/2024.
//

#include "Voxel.h"



Voxel::Voxel()  : Voxel(VoxelPos(0,0,0)){}

Voxel::Voxel(VoxelPos pos, bool isTransparent)
    : mPosition(pos), mIsTransparent(isTransparent)
{

}

Voxel::~Voxel() {

}
