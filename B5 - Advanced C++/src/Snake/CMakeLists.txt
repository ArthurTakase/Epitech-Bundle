cmake_minimum_required(VERSION 3.16)
project(Snake LANGUAGES CXX)

add_executable(${PROJECT_NAME} Snake.cpp)

target_link_libraries(${PROJECT_NAME} ECSEncapsulation)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../include)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
