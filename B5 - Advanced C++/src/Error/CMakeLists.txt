cmake_minimum_required(VERSION 3.16)
project(Error LANGUAGES CXX)

add_library(${PROJECT_NAME} STATIC Error.cpp)

target_include_directories(Error PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../include)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
set_property(TARGET Error PROPERTY POSITION_INDEPENDENT_CODE ON)
