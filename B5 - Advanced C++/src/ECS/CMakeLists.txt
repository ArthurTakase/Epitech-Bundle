cmake_minimum_required(VERSION 3.17)
project(ECSEncapsulation)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-g")

# Sources
set(
  SRC
  Entity/Entity.cpp
  Entity/EntityManager.cpp
  Components/TransformComponent.cpp
  Components/HitboxComponent.cpp
  Components/MouvementComponent.cpp
  Components/StatComponent.cpp
  Components/DrawableComponent.cpp
  Components/BehaviorComponent.cpp
  Components/AnimationComponent.cpp
  Components/InputComponent.cpp
  Components/DestroyableComponent.cpp
  Components/TimerComponent.cpp
  Components/SoundComponent.cpp
  Components/MusicComponent.cpp
  Components/TextComponent.cpp
  Systems/HitboxSystem.cpp
  Systems/MouvementSystem.cpp
  Systems/BehaviorSystem.cpp
  Systems/AnimationSystem.cpp
  Systems/DrawableSystem.cpp
  Systems/DestroyableSystem.cpp
  Systems/SoundSystem.cpp
  Systems/MusicSystem.cpp
)

add_library(${PROJECT_NAME} STATIC ${SRC})

target_link_libraries(${PROJECT_NAME} CMakeSFMLProject)
target_link_libraries(${PROJECT_NAME} JSONTools)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../include)