cmake_minimum_required(VERSION 3.27)
project(Voxel_Renderer)

set(CMAKE_CXX_STANDARD 23)

# Engine
include_directories(engine/src)
add_subdirectory(engine)

add_executable(Voxel_Renderer main.cpp)

target_link_libraries(Voxel_Renderer
        PRIVATE
        Voxel_Engine
)
