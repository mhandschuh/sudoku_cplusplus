//
// Created by Michael on 11.07.2017.
//

#ifndef SUDOKU_SUDOKUBOARD_H
#define SUDOKU_SUDOKUBOARD_H


class SudokuBoard {
private:
    int givenValues[9][9];
public:
    int playerValues[9][9];

    SudokuBoard(int (*grid)[9][9]);
    void Reset(void);
    void Print(void);


};


#endif //SUDOKU_SUDOKUBOARD_H
