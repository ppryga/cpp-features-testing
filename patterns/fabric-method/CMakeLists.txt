cmake_minimum_required(VERSION 3.0.0)
project(pattern-fabric-method VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(pattern-fabric-method src/main.cpp
        src/shape-creator.cpp
        src/square-creator.cpp)

target_include_directories(pattern-fabric-method PUBLIC src)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
