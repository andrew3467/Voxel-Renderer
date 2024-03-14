//
// Created by Andrew Graser on 3/11/2024.
//

#ifndef VOXEL_RENDERER_CHUNK_H
#define VOXEL_RENDERER_CHUNK_H

#define CHUNK_SIZE_X 32
#define CHUNK_SIZE_Y 32
#define CHUNK_SIZE_Z 32
#define VOXELS_IN_CHUNK CHUNK_SIZE_X * CHUNK_SIZE_Y * CHUNK_SIZE_Z

#define ADJACENT_MASK_ALL 0x3F
#define ADJACENT_MASK_NEG_X 1 << 0
#define ADJACENT_MASK_POS_X 1 << 1
#define ADJACENT_MASK_NEG_Y 1 << 2
#define ADJACENT_MASK_POS_Y 1 << 3
#define ADJACENT_MASK_NEG_Z 1 << 4
#define ADJACENT_MASK_POS_Z 1 << 5

#define WORLD_SIZE_X 2
#define WORLD_SIZE_Z 2

#include <glm/glm.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/hash.hpp"
#include "Voxel.h"


//std
#include <vector>



#define AIR 0
#define GRASS 1


//From VoxelData
struct Vertex;


typedef glm::vec3 ChunkPos;

class Chunk {
public:
    Chunk(const ChunkPos& pos);

    ~Chunk();


    void AddFace(Vertex vertices[], const glm::vec3& pos);
    void GenerateMesh();
    void Render();

private:


private:
    ChunkPos mChunkPos;
    ChunkPos mGlobalChunkPos;

    uint32_t mVertexArray;
    std::vector<Vertex> mVertices;
};


#endif //VOXEL_RENDERER_CHUNK_H
