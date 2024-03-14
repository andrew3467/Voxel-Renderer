cmake_minimum_required(VERSION 3.27)
project(Voxel_Engine)

set(CMAKE_CXX_STANDARD 23)

# GLAD
include_directories(external/glad/include)
add_subdirectory(external/glad)

# GLFW
include_directories(external/glfw/include)
add_subdirectory(external/glfw)
#Tell glfw not to include OpenGL
add_compile_definitions(GLFW_INCLUDE_NONE)

# GLM
include_directories(external/glm)
add_subdirectory(external/glm)

# FastNoise
include_directories(external/FastNoiseLite/include)



file(GLOB_RECURSE SRC src/*.cpp)
file(GLOB_RECURSE HEADERS src/*.h)


add_library(Voxel_Engine
    ${SRC}
    ${HEADERS}
        external/FastNoiseLite/include/fastnoiselite/FastNoiseLite.h
)

target_link_libraries(Voxel_Engine
        PUBLIC
        glad
        glfw
        glm
)
