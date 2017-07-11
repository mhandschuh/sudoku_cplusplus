#ifndef SUDOKU_BACKTRACKSOLVER_H
#define SUDOKU_BACKTRACKSOLVER_H


#include <tuple>
#include "SudokuSolver.h"

class BackTrackSolver : public SudokuSolver {

private:
    std::tuple<int, int> findFirstEmptyCell(int i, int j);
public:
    BackTrackSolver(int (*grid)[9][9]) : SudokuSolver(grid) {}

    bool Solve(int i, int j) override;

    bool Solve() override;
};


#endif //SUDOKU_BACKTRACKSOLVER_H
