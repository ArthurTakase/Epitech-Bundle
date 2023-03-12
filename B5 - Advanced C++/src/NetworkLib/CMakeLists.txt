# CmakeLists to create the network library
cmake_minimum_required(VERSION 3.17)
project(NetworkLib)

set(SRC
  LinuxSocketSelector.cpp
  LinuxSocket.cpp
  SocketFactory.cpp
  SocketSelectorFactory.cpp
  WindowsSocket.cpp
  WindowsSocketSelector.cpp
  HostHandler.cpp
)

add_library(${PROJECT_NAME} STATIC ${SRC})

if(WIN32)
  target_link_libraries(${PROJECT_NAME} wsock32 ws2_32)
endif()


target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../include)
target_link_libraries(${PROJECT_NAME} Error)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)