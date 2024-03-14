//
// Created by Andrew Graser on 3/12/2024.
//

#include <stdexcept>
#include <iostream>

#include "Level.h"
#include "fastnoiselite/FastNoiseLite.h"
#include "glm/gtx/string_cast.hpp"

#define NOISE_SCALE .2f


int Index1DFrom3D(int x, int y, int z){
    return (z * CHUNK_SIZE_X * CHUNK_SIZE_Y) + (y * CHUNK_SIZE_X) + x;
}

int Index1DFrom3D(glm::vec3 v){
    return Index1DFrom3D(v.x, v.y, v.z);
}

Level* Level::sInstance = nullptr;

Level::Level() {
    sInstance = this;
}

Level::~Level() {

}

void Level::CreateChunks() {
    for(int x = -WORLD_SIZE_X / 2; x < WORLD_SIZE_X; x++){
        for(int z = -WORLD_SIZE_Z / 2; z < WORLD_SIZE_Z; z++){
            CreateChunk({x, 0, z});
        }
    }
}

void Level::RenderChunks() {
    for(const auto& kv : mChunkManager){
        auto& chunk = kv.second;
        chunk->Render();
    }
}

void Level::GenerateChunkData(ChunkPos pos) {
    ChunkPos scaledPos = pos * glm::vec3(CHUNK_SIZE_X, CHUNK_SIZE_Y, CHUNK_SIZE_Z);

    FastNoiseLite noise(33425);
    noise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);

    for(int x = 0; x < CHUNK_SIZE_X; x++)
    for(int z = 0; z < CHUNK_SIZE_Z; z++){
        float noiseValue = (noise.GetNoise(((float)x + scaledPos.x) / NOISE_SCALE, ((float)z + scaledPos.z) / NOISE_SCALE));
        //Normalize between 0 and 1
        noiseValue = (noiseValue + 1.0f) / 2.0f;
        int height = floor(noiseValue * CHUNK_SIZE_Y);

        for(int y = 0; y < CHUNK_SIZE_Y; y++){
            mVoxels[VoxelPos(x,y,z) + scaledPos] = Voxel(VoxelPos(x,y,z) + scaledPos, y > height);
        }
    }
}

void Level::CreateChunk(ChunkPos pos) {
    GenerateChunkData(pos);
    mChunkManager.CreateChunk(pos);
}

Voxel* Level::GetVoxel(VoxelPos pos) {

    auto it = mVoxels.find(pos);
    if (it != mVoxels.end()) {
        return &it->second;
    }

    return nullptr;
}
