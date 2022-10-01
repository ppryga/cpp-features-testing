cmake_minimum_required(VERSION 3.0.0)
project(pattern-builder VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(pattern-builder src/main.cpp
        src/car.cpp
        src/bmw-builder.cpp
        src/tesla-builder.cpp)

target_include_directories(pattern-builder PUBLIC src)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
