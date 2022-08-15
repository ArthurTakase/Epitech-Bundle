cmake_minimum_required(VERSION 3.17)
project(bomberman)

set(OpenGL_GL_PREFERENCE GLVND)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-g")

if(UNIX)
  find_program(TIDY "clang-tidy")
  if(TIDY)
    set(CMAKE_CXX_CLANG_TIDY "clang-tidy")
  endif()
endif()

if(CMAKE_BUILD_TYPE MATCHES Debug)
  set(CMAKE_VERBOSE_MAKEFILE ON)
endif()

file(COPY assets/ DESTINATION assets/)

set(
  INDIE_SRC
  src/main.cpp

  src/Engine/Tools/Timer.cpp
  src/Engine/Tools/Error.cpp

  src/Engine/ECS/Components/AI.cpp
  src/Engine/ECS/Components/BoxCollider.cpp
  src/Engine/ECS/Components/Transform3D.cpp
  src/Engine/ECS/Components/Render.cpp
  src/Engine/ECS/System/ACore.cpp
  src/Engine/ECS/System/AData.cpp
  src/Engine/ECS/System/AWindow.cpp
  src/Indie/GameCore/Core.cpp
  src/Indie/GameCore/GameData.cpp
  src/Indie/GameCore/MyCameraman.cpp
  src/Indie/GameCore/Save.cpp

  src/Indie/Prefabs/Player.cpp
  src/Indie/Prefabs/Bomb.cpp
  src/Indie/Prefabs/Crate.cpp
  src/Indie/Prefabs/Wall.cpp
  src/Indie/Prefabs/Fire.cpp
  src/Indie/Prefabs/Item.cpp

  src/Indie/Scenes/Game.cpp
  src/Indie/Scenes/Home.cpp
  src/Indie/Scenes/PlayerSelect.cpp
  src/Indie/Scenes/Splash.cpp
  src/Indie/Scenes/Load.cpp
  src/Indie/UI/Button.cpp
)

add_executable(${PROJECT_NAME} ${INDIE_SRC})

add_subdirectory(src/Lib)
target_link_libraries(${PROJECT_NAME} raylib_encapsulation)

# Ajouter ici les dossiers contenants les .hpp
target_include_directories(${PROJECT_NAME} PRIVATE include/Engine/ECS/Components)
target_include_directories(${PROJECT_NAME} PRIVATE include/Engine/ECS)
target_include_directories(${PROJECT_NAME} PRIVATE include/Engine/ECS/System)
target_include_directories(${PROJECT_NAME} PRIVATE include/Engine/Tools)
target_include_directories(${PROJECT_NAME} PRIVATE include/Engine)
target_include_directories(${PROJECT_NAME} PRIVATE include/Indie/Scenes)
target_include_directories(${PROJECT_NAME} PRIVATE include/Indie/Prefabs)
target_include_directories(${PROJECT_NAME} PRIVATE include/Indie/UI)
target_include_directories(${PROJECT_NAME} PRIVATE include/Indie/GameCore)
target_include_directories(${PROJECT_NAME} PRIVATE src/Lib/include)

target_compile_options(${PROJECT_NAME} PUBLIC ${CXX_FLAGS})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
