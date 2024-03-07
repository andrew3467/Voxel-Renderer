cmake_minimum_required(VERSION 3.27)
project(Voxel_Engine)

set(CMAKE_CXX_STANDARD 23)

# GLAD
include_directories(external/glad/include)
add_subdirectory(external/glad)

# GLFW
include_directories(external)


add_library(Voxel_Engine
    ${SRC}
    ${HEADERS}
)
