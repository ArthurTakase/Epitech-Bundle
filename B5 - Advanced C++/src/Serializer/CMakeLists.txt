cmake_minimum_required(VERSION 3.16)
project(Serializer LANGUAGES CXX)

add_library(${PROJECT_NAME} STATIC Serializer.cpp)

target_link_libraries(${PROJECT_NAME} ECSEncapsulation)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../include)
