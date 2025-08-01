cmake_minimum_required(VERSION 3.16)
project(SENGINE2 VERSION 1.0.0)
cmake_policy(SET CMP0072 NEW)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)

add_executable(SENGINE2 
    src/config.h
    src/config.cpp 
    src/main.cpp 
    src/glad.c
    src/TriangleMesh.h
    src/TriangleMesh.cpp
    src/Engine.h
    src/Engine.cpp
    src/Window.h
    src/Window.cpp
    src/Renderer.h
    src/Renderer.cpp
    src/Material.cpp
    src/Scene.cpp
    src/Entity.cpp
    src/RenderSystem.cpp
    src/Model.h
    src/Model.cpp
    src/Mesh.h
    src/Mesh.cpp
    src/components/ModelComponent.h
    src/components/ModelComponent.cpp
    src/components/TransformComponent.h
    src/components/TransformComponent.cpp
    )

find_package(glm REQUIRED)
target_include_directories(SENGINE2 PRIVATE dependencies glm)

find_package(glfw3 REQUIRED)
find_package(assimp REQUIRED)

target_link_libraries(SENGINE2 glfw OpenGL::GL assimp::assimp) 

target_compile_options(SENGINE2 PRIVATE -fsanitize=address -g)
target_link_options(SENGINE2 PRIVATE -fsanitize=address)

target_include_directories(SENGINE2 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/entt/single_include
)

set(CMAKE_BUILD_TYPE Debug)

