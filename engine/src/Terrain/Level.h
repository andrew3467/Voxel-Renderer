//
// Created by Andrew Graser on 3/12/2024.
//

#ifndef VOXEL_RENDERER_LEVEL_H
#define VOXEL_RENDERER_LEVEL_H

#include "ChunkManager.h"
#include "Voxel.h"


//std
#include <unordered_map>
#include <memory>
#include <unordered_map>

class Level {
public:
    explicit Level();
    ~Level();

    void RenderChunks();

    inline static Level& GetInstance() {return *sInstance;}

    Voxel* GetVoxel(VoxelPos pos);

    ChunkManager& GetChunkManager() {return mChunkManager;}
    void CreateChunk(ChunkPos pos);

    void CreateChunks();

private:
    //Generate voxels for specified chunk
    void GenerateChunkData(ChunkPos pos);

private:
    static Level* sInstance;

    ChunkManager mChunkManager;

    std::unordered_map<VoxelPos, Voxel> mVoxels;
};


#endif //VOXEL_RENDERER_LEVEL_H
