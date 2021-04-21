cmake_minimum_required(VERSION 3.17)
project(binary_search)

# Locate GTest
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 20)
enable_testing()
add_executable(binary_search main.cpp find.h tests.cpp)

target_link_libraries(binary_search ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
