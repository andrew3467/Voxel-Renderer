//
// Created by Andrew Graser on 3/12/2024.
//

#include "ChunkManager.h"



ChunkManager::ChunkManager() {

}

ChunkManager::~ChunkManager() {

}

bool ChunkManager::CreateChunk(ChunkPos pos) {
    if(mChunks.contains(pos)){
        throw std::runtime_error("Error: tried to create duplicate chunk!");
        return false;
    }

    mChunks[pos] = std::make_unique<Chunk>(pos);
    return true;
}
