cmake_minimum_required(VERSION 3.17)
project(JSONTools LANGUAGES CXX)

# Download this repository
include(FetchContent)
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)

add_library(${PROJECT_NAME} STATIC JsonTools.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC nlohmann_json::nlohmann_json)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../include)
