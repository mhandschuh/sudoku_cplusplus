#include <iostream>
#include <chrono>
#include "SudokuBoard.h"
#include "BackTrackSolver.h"

int main() {
    int given[9][9] = {
            {5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 0, 0, 0, 6, 0},
            {8, 0, 0, 0, 6, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    SudokuBoard board(&given);

    std::cout << "Input ----------------" << std::endl;
    board.Print();
    std::cout << std::endl;
    BackTrackSolver solver(&board.playerValues);

    std::cout << "Solution -------------" << std::endl;

    auto start = std::chrono::system_clock::now();
    bool isSuccessful = solver.Solve();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds> (std::chrono::system_clock::now() - start);

    std::cout << duration.count() << std::endl;

    if (isSuccessful) {
        board.Print();
    } else {
        std::cout << "No feasible solution found" << std::endl;
    }

    return 0;
}