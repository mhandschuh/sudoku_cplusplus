cmake_minimum_required(VERSION 3.7)
project(sudoku)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp SudokuBoard.cpp SudokuBoard.h SudokuSolver.cpp SudokuSolver.h BackTrackSolver.cpp BackTrackSolver.h)
add_executable(sudoku ${SOURCE_FILES})