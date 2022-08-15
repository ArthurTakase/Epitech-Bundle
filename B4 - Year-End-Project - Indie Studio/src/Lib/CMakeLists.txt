set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
find_package(raylib 4.0.0 REQUIRED)

add_library(
    raylib_encapsulation
    STATIC
    Animation.cpp
    AudioDevice.cpp
    Cameraman.cpp
    CollisionChecker.cpp
    Color.cpp
    Controller.cpp
    DeltaTime.cpp
    Fps.cpp
    Model3D.cpp
    Mouse.cpp
    Music.cpp
    Plane.cpp
    Rectangle.cpp
    Sound.cpp
    Sprite.cpp
    Text.cpp
    Window.cpp
    Round.cpp
)
set_property(TARGET raylib_encapsulation PROPERTY CXX_STANDARD 20)
set_property(TARGET raylib_encapsulation PROPERTY POSITION_INDEPENDENT_CODE ON)

target_include_directories(raylib_encapsulation PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(raylib_encapsulation PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(raylib_encapsulation PUBLIC ../Engine/ECS/System)

target_link_libraries(raylib_encapsulation raylib)