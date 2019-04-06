cmake_minimum_required(VERSION 3.9.2)
include(CMake/platform.cmake)
project(AngryNErds)

## out of source builds ##
set(CMAKE_DEBUG_POSTFIX d)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY  "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  "${CMAKE_BINARY_DIR}/bin")

## set to true to use dlls instead of static libs ##
option(STATIC_APP "Build a static application" ON)
if( STATIC_APP )
    message("##### BUILDING STATIC APPLICATION #####")
    set(BUILD_SHARED_LIBS false)
else()
    message("##### BUILDING SHARED APPLICATION #####")
    set(BUILD_SHARED_LIBS true)
endif()

## itch.io and gamedata settings ##
set(GAMEDATA_FOLDER "GameData")
set(ITCHIO_USER     "")

## files used to build this game
add_executable(
        ${PROJECT_NAME}
        "Source/main.cpp"
        "Source/Game.h"
        "Source/Game.cpp"
        "Source/Components/GameObject.h"
        "Source/Components/GameObject.cpp"
        "Source/Components/SpriteComponent.h"
        "Source/Components/SpriteComponent.cpp"
        "Source/Utility/Rectangle.h"
        "Source/Utility/Rectangle.cpp"
        "Source/Utility/Vector2.h"
        "Source/Utility/Vector2.cpp"
        "Source/Utility/Circle.cpp"
        "Source/Utility/Circle.h" Source/Components/PhysicsComponent.cpp Source/Components/PhysicsComponent.h Source/Bird.cpp Source/Bird.h Source/Block.cpp Source/Block.h Source/Pig.cpp Source/Pig.h Source/Collision.cpp Source/Collision.h Source/Level.cpp Source/Level.h)

## utility scripts
set(ENABLE_SOUND OFF CACHE BOOL "Adds SoLoud to the Project" FORCE)
include(CMake/compilation.cmake)
include(CMake/datpak.cmake)
