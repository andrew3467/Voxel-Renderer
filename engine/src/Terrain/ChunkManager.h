//
// Created by Andrew Graser on 3/12/2024.
//

#ifndef VOXEL_RENDERER_CHUNKMANAGER_H
#define VOXEL_RENDERER_CHUNKMANAGER_H


#include <memory>
#include "Chunk.h"

using ChunkData = std::unordered_map<ChunkPos, std::unique_ptr<Chunk>>;

class ChunkManager {
public:
    ChunkManager();
    ~ChunkManager();

    bool CreateChunk(ChunkPos pos);

    ChunkData::iterator begin() {return mChunks.begin();}
    ChunkData::iterator end() {return mChunks.end();}

    ChunkData::const_iterator begin() const {return mChunks.begin();}
    ChunkData::const_iterator end() const {return mChunks.end();}

private:
    ChunkData mChunks;
};


#endif //VOXEL_RENDERER_CHUNKMANAGER_H
