cmake_minimum_required(VERSION 3.10)
project(CellsProject)

# Add the subdirectory containing GoogleTest's CMakeLists.txt
# Let's assume Google Test is stored in a directory called "googletest"
add_subdirectory(test)

add_library(Cells Cells.cpp)
