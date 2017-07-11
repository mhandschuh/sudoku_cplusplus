#include <list>
#include "SudokuSolver.h"
#include "BackTrackSolver.h"


bool BackTrackSolver::Solve() {
    return BackTrackSolver::Solve(0, 0);
}

bool BackTrackSolver::Solve(int i, int j) {
    std::tie(i, j) = BackTrackSolver::findFirstEmptyCell(i, j);

    if (i == -1) {
        return true;
    }
    int topLeftX = 3 * (i / 3);
    int topLeftY = 3 * (j / 3);

    std::list<int> validValues;
    for (int numIdx = 0; numIdx < 9; numIdx++) {
        validValues.push_back(numIdx + 1);
    }

    // remove values from 3x3 box
    for (int idx = 0; idx <= 2; idx++) {
        validValues.remove((*solveGrid)[topLeftX][topLeftY + idx]);
        validValues.remove((*solveGrid)[topLeftX + 1][topLeftY + idx]);
        validValues.remove((*solveGrid)[topLeftX + 2][topLeftY + idx]);
    }
    //remove values from column
    for (int rowIdx = 0; rowIdx < 9; rowIdx++) {
        validValues.remove((*solveGrid)[rowIdx][j]);
    }
    //remove values from row
    for (int colIdx = 0; colIdx < 9; colIdx++) {
        validValues.remove((*solveGrid)[i][colIdx]);
    }

    for (std::list<int>::iterator it = validValues.begin(); it != validValues.end(); it++) {
        int guess = *it;
        (*solveGrid)[i][j] = guess;

        if (BackTrackSolver::Solve(i, j)) {
            return true;
        }
        (*solveGrid)[i][j] = 0;
    }
    return false;
}

std::tuple<int, int> BackTrackSolver::findFirstEmptyCell(int i, int j) {
    for (int x = i; x < 9; x++) {
        for (int y = j; y < 9; y++) {
            if ((*solveGrid)[x][y] == 0) {
                return std::tuple<int, int>(x, y);
            }
        }
    }

    for(int x=0;x<9;x++) {
        for(int y=0;y<9;y++) {
            if((*solveGrid)[x][y] == 0) {
                return std::tuple<int, int>(x, y);
            }
        }
    }
    return std::tuple<int, int>(-1, -1);
}
