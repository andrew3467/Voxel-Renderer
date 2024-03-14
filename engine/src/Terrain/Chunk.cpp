//
// Created by Andrew Graser on 3/11/2024.
//

#include <iostream>
#include "Chunk.h"
#include "Renderer/Renderer.h"
#include "VoxelData.h"
#include "Level.h"

#include "glm/ext/matrix_transform.hpp"


#include <Glad/glad.h>



Chunk::Chunk(const ChunkPos& pos)
        : mChunkPos(pos)
{
    mGlobalChunkPos = mChunkPos * glm::vec3(CHUNK_SIZE_X, CHUNK_SIZE_Y, CHUNK_SIZE_Z);

    GenerateMesh();
}

Chunk::~Chunk() {

}

void Chunk::GenerateMesh() {
    for(int x = 0; x < CHUNK_SIZE_X; x++)
    for(int y = 0; y < CHUNK_SIZE_Y; y++)
    for(int z = 0; z < CHUNK_SIZE_Z; z++){
        VoxelPos pos(x,y,z);
        VoxelPos globalPos = pos + mGlobalChunkPos;

        auto& level = Level::GetInstance();
        auto b = level.GetVoxel(globalPos);

        if(b== nullptr){
            int a = 1;
        }

        if(b != nullptr && b->IsTransparent()) continue;

        auto bnx = level.GetVoxel(globalPos + VoxelData::Facing::Left);
        auto bpx = level.GetVoxel(globalPos + VoxelData::Facing::Right);
        auto bny = level.GetVoxel(globalPos + VoxelData::Facing::Bottom);
        auto bpy = level.GetVoxel(globalPos + VoxelData::Facing::Top);
        auto bnz = level.GetVoxel(globalPos + VoxelData::Facing::Back);
        auto bpz = level.GetVoxel(globalPos + VoxelData::Facing::Front);


        int opaqueMask = 0;
        if(bnx != nullptr && (bnx->IsOpaque() || b == bnx)) opaqueMask |= ADJACENT_MASK_NEG_X;
        if(bpx != nullptr && (bpx->IsOpaque() || b == bpx)) opaqueMask |= ADJACENT_MASK_POS_X;
        if(bny != nullptr && (bny->IsOpaque() || b == bny)) opaqueMask |= ADJACENT_MASK_NEG_Y;
        if(bpy != nullptr && (bpy->IsOpaque() || b == bpy)) opaqueMask |= ADJACENT_MASK_POS_Y;
        if(bnz != nullptr && (bnz->IsOpaque() || b == bnz)) opaqueMask |= ADJACENT_MASK_NEG_Z;
        if(bpz != nullptr && (bpz->IsOpaque() || b == bpz)) opaqueMask |= ADJACENT_MASK_POS_Z;




        if(opaqueMask == ADJACENT_MASK_ALL){
            continue;
        }

        //Add faces
        if((opaqueMask & ADJACENT_MASK_NEG_X) == 0){
            AddFace(VoxelData::LeftFace, pos);
        }
        if((opaqueMask & ADJACENT_MASK_POS_X) == 0){
            AddFace(VoxelData::RightFace, pos);
        }

        if((opaqueMask & ADJACENT_MASK_NEG_Z) == 0){
            AddFace(VoxelData::BackFace, pos);
        }
        if((opaqueMask & ADJACENT_MASK_POS_Z) == 0){
            AddFace(VoxelData::FrontFace, pos);
        }

        if((opaqueMask & ADJACENT_MASK_NEG_Y) == 0){
            AddFace(VoxelData::BottomFace, pos);
        }
        if((opaqueMask & ADJACENT_MASK_POS_Y) == 0){
            AddFace(VoxelData::TopFace, pos);
        }
    }



    glGenVertexArrays(1, &mVertexArray);
    glBindVertexArray(mVertexArray);

    uint32_t VB;
    glGenBuffers(1, &VB);
    glBindBuffer(GL_ARRAY_BUFFER, VB);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * mVertices.size(), mVertices.data(), GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Position));

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Color));

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, TexCoord));
}

void Chunk::Render() {
    auto transform = glm::translate(glm::mat4(1.0f), mGlobalChunkPos);

    Renderer::Submit(mVertexArray, mVertices.size(), glm::vec3(1.0f), transform);
}

void Chunk::AddFace(Vertex *vertices, const glm::vec3& pos) {
    for(int i = 0; i < 6; i++)
        mVertices.emplace_back(
                vertices[i].Position + pos,
                glm::normalize(pos),
                vertices[i].TexCoord
        );
}
