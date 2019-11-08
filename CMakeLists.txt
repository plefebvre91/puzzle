project(Puzzle)

cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_FLAGS "-Wextra -Wall -pedantic --std=c++17 -g")

include_directories(include)

set(SRC_FILES src/main.cpp
  src/board.cpp
  src/tile.cpp
  src/puzzle.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

link_libraries( sfml-graphics sfml-window sfml-system pthread)

add_executable(puzzle ${SRC_FILES})
