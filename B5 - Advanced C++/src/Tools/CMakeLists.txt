cmake_minimum_required(VERSION 3.16)
project(Tools LANGUAGES CXX)

add_library(${PROJECT_NAME} STATIC Curve.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../include)
