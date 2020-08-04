cmake_minimum_required(VERSION 3.5)

project(VectorTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(VectorTest main.cpp)

target_link_libraries(VectorTest ${GTEST_BOTH_LIBRARIES})

add_test(AllVectorTests VectorTest)
