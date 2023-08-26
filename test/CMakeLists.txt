cmake_minimum_required(VERSION 3.10)
project(CellsTest)

# Add the test executable
add_executable(CellsTest CellsTest.cpp)

# Link the test executable with GoogleTest and the main library
target_link_libraries(CellsTest gtest gtest_main Cells)
