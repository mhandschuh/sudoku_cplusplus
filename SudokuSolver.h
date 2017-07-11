#ifndef SUDOKU_SUDOKUSOLVER_H
#define SUDOKU_SUDOKUSOLVER_H


class SudokuSolver {
protected:
    int (*solveGrid)[9][9];
public:
    SudokuSolver(int (*grid)[9][9]);
    virtual bool Solve(int i, int j) = 0;
    virtual bool Solve() = 0;
};


#endif //SUDOKU_SUDOKUSOLVER_H
