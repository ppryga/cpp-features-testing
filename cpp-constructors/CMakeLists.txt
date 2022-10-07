cmake_minimum_required(VERSION 3.0.0)
project(cpp-constructors VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(cpp-constructors src/main.cpp
        src/no-throw-constructor.cpp
        src/throwing-constuctor.cpp
        src/set-result-flag-constructor.cpp
        src/static-method-constructor.cpp)

target_include_directories(cpp-constructors PUBLIC src)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
