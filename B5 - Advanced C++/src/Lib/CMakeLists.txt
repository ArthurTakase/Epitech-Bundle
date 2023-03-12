cmake_minimum_required(VERSION 3.16)
project(CMakeSFMLProject LANGUAGES CXX)

# Force the script to use FetchContent and not CPM internally to fetch asio
option(SFML_USE_CPM "Download SFML with CPM instead of FetchContent" OFF)
option(
  SFML_CPM_FETCHCONTENT_COMPAT
  "Should SFML be declared with FetchContent functions to be compatible. This doesn't not allow CPM cache to work."
  ON
)

# Download this repository
include(FetchContent)
FetchContent_Declare(
  sfml
  URL https://github.com/SFML/SFML/archive/refs/heads/master.zip
)
FetchContent_MakeAvailable(sfml)

set(SRC
  Lib.cpp
  Window.cpp
  Sprite.cpp
  Timer.cpp
  Text.cpp
  Sound.cpp
  Music.cpp
  SoundManager.cpp
)

add_library(${PROJECT_NAME} STATIC ${SRC})

target_link_libraries(${PROJECT_NAME} PUBLIC sfml-graphics sfml-window sfml-system sfml-audio)
target_link_libraries(${PROJECT_NAME} PUBLIC Error)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../include)