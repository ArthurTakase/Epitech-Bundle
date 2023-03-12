cmake_minimum_required(VERSION 3.17)
project(R-Type)

# ------------------------------
# R-TYPE
# ------------------------------
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-g")

set(TEST_BUILD runTests)

if(UNIX)
  if(DEFINED CLANG)
    find_program(TIDY "clang-tidy")

    if(TIDY)
      set(CMAKE_CXX_CLANG_TIDY "clang-tidy")
    endif()
  endif()
endif()

if(CMAKE_BUILD_TYPE MATCHES Debug)
  set(CMAKE_VERBOSE_MAKEFILE ON)
endif()

file(COPY assets/ DESTINATION assets/)

# Libs
add_subdirectory(src/Error)
add_subdirectory(src/NetworkLib)
add_subdirectory(src/Lib)
add_subdirectory(src/ECS)
add_subdirectory(src/Serializer)
add_subdirectory(src/Json)
add_subdirectory(src/Tools)
add_subdirectory(src/Time)

if(DEFINED SNAKE)
  add_subdirectory(src/Snake)
endif()

# ------------------------------
# Server
# ------------------------------
set(RTYPE_SERVER r-type_server)
set(SERVER_DIR src/Server)

set(RTYPE_SERVER_SRC
  ${SERVER_DIR}/Server.cpp
  ${SERVER_DIR}/RType.cpp
  ${SERVER_DIR}/RType/Asteroid.cpp
  ${SERVER_DIR}/RType/Enemies.cpp
  ${SERVER_DIR}/RType/Boss.cpp
  ${SERVER_DIR}/RType/Misc.cpp
  ${SERVER_DIR}/RType/Player.cpp
  ${SERVER_DIR}/RType/Spawner.cpp
)

add_executable(${RTYPE_SERVER} ${SERVER_DIR}/main.cpp ${RTYPE_SERVER_SRC})

if(WIN32)
  target_link_libraries(${RTYPE_SERVER} wsock32 ws2_32)
endif()

target_link_libraries(${RTYPE_SERVER} Error)
target_link_libraries(${RTYPE_SERVER} NetworkLib)
target_link_libraries(${RTYPE_SERVER} ECSEncapsulation)
target_link_libraries(${RTYPE_SERVER} CMakeSFMLProject)
target_link_libraries(${RTYPE_SERVER} Serializer)
target_link_libraries(${RTYPE_SERVER} Tools)
target_link_libraries(${RTYPE_SERVER} Time)

set_property(TARGET ${RTYPE_SERVER} PROPERTY CXX_STANDARD 20)
target_compile_options(${RTYPE_SERVER} PUBLIC ${CXX_FLAGS})

target_include_directories(${RTYPE_SERVER} PRIVATE include)

# ------------------------------
# Client
# ------------------------------
set(RTYPE_CLIENT r-type_client)
set(CLIENT_DIR src/Client)

set(RTYPE_CLIENT_SRC
  ${CLIENT_DIR}/UdpClient.cpp
  ${CLIENT_DIR}/Game.cpp
  ${CLIENT_DIR}/Menu.cpp
)

add_executable(${RTYPE_CLIENT} ${CLIENT_DIR}/main.cpp ${RTYPE_CLIENT_SRC})

target_link_libraries(${RTYPE_CLIENT} Error)
target_link_libraries(${RTYPE_CLIENT} NetworkLib)
target_link_libraries(${RTYPE_CLIENT} ECSEncapsulation)
target_link_libraries(${RTYPE_CLIENT} CMakeSFMLProject)
target_link_libraries(${RTYPE_CLIENT} Time)

target_compile_options(${RTYPE_CLIENT} PUBLIC ${CXX_FLAGS})
set_property(TARGET ${RTYPE_CLIENT} PROPERTY CXX_STANDARD 20)

target_include_directories(${RTYPE_CLIENT} PRIVATE include)

# ------------------------------
# TESTS
# ------------------------------
if(DEFINED TESTS)
  include(FetchContent)
  FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    SOURCE_DIR ${CMAKE_BINARY_DIR}/googletest-src
  )
  FetchContent_GetProperties(googletest)

  if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src ${CMAKE_BINARY_DIR}/googletest-build)
  endif()

  if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
  endif()

  # Sources
  set(
    TESTS_SRC
    tests/ECS/Components/HitboxComponent_t.cpp
    tests/ECS/Components/TransformComponent_t.cpp
    tests/ECS/Components/MouvementComponent_t.cpp
    tests/ECS/Components/BehaviorComponent_t.cpp
    tests/ECS/Components/DestroyableComponent_t.cpp
    tests/ECS/Components/InputComponent_t.cpp
    tests/ECS/Components/StatComponent_t.cpp

    tests/ECS/Entity/Entity_t.cpp
    tests/ECS/Entity/EntityManager_t.cpp

    tests/ECS/Systems/HitboxSystem_t.cpp
    tests/ECS/Systems/MouvementSystem_t.cpp
    tests/ECS/Systems/BehaviorSystem_t.cpp
    tests/ECS/Systems/DestroyableSystem_t.cpp

    tests/Tools/EntityIterator_t.cpp
    tests/Tools/Tools_t.cpp
    tests/Tools/Curve_t.cpp
    tests/Tools/JsonTools_t.cpp
    tests/Tools/Error_t.cpp
  )

  set(
    ALL_SRC

    src/ECS/Components/BehaviorComponent.cpp
    src/ECS/Components/DestroyableComponent.cpp
    src/ECS/Components/HitboxComponent.cpp
    src/ECS/Components/InputComponent.cpp
    src/ECS/Components/MouvementComponent.cpp
    src/ECS/Components/StatComponent.cpp
    src/ECS/Components/TransformComponent.cpp

    src/ECS/Entity/Entity.cpp
    src/ECS/Entity/EntityManager.cpp

    src/ECS/Systems/BehaviorSystem.cpp
    src/ECS/Systems/DestroyableSystem.cpp
    src/ECS/Systems/HitboxSystem.cpp
    src/ECS/Systems/MouvementSystem.cpp

    src/Tools/Curve.cpp
  )

  # Merge
  add_executable(${TEST_BUILD} ${ALL_SRC} ${TESTS_SRC} ${RTYPE_SERVER_SRC} ${RTYPE_CLIENT_SRC})

  # Options
  target_link_libraries(${TEST_BUILD} Error)
  target_link_libraries(${TEST_BUILD} NetworkLib)
  target_link_libraries(${TEST_BUILD} CMakeSFMLProject)
  target_link_libraries(${TEST_BUILD} ECSEncapsulation)
  target_link_libraries(${TEST_BUILD} Serializer)
  target_link_libraries(${TEST_BUILD} Tools)
  target_link_libraries(${TEST_BUILD} Time)
  target_link_libraries(${TEST_BUILD} gtest gtest_main gmock pthread)

  # Includes
  target_include_directories(${TEST_BUILD} PRIVATE include)
  target_include_directories(${TEST_BUILD} PRIVATE ${CMAKE_BINARY_DIR}/googletest-src/googletest/include)
  target_include_directories(${TEST_BUILD} PRIVATE ${CMAKE_BINARY_DIR}/googletest-src/googlemock/include)
endif()
