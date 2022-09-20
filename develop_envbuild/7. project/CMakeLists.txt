cmake_minimum_required(VERSION 3.0)

project(GAME)

set(CMAKE_CXX_KNOWN_FEATURES "${CMAKE_CXX_FEATURES} -g -o2 -Wall")

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(cmake_exe main.cpp src/gun.cpp src/solider.cpp)
