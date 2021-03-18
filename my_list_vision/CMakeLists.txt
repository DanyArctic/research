cmake_minimum_required(VERSION 3.17)
project(my_list_vision)

# Locate GTest
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 20)
enable_testing()
add_executable(my_list_vision main.cpp List.cpp List.h Node.cpp Node.h tests.cpp)

target_link_libraries(my_list_vision ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})