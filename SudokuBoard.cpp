#include <algorithm>
#include <iostream>
#include "SudokuBoard.h"

SudokuBoard::SudokuBoard(int (*grid)[9][9]) {
    std::copy(&(*grid)[0][0], &(*grid)[0][0] + 9 * 9, &givenValues[0][0]);
    std::copy(&(*grid)[0][0], &(*grid)[0][0] + 9 * 9, &playerValues[0][0]);
}

void SudokuBoard::Reset(void) {
    std::copy(&givenValues[0][0], &givenValues[0][0] + 9 * 9, &playerValues[0][0]);
}

void SudokuBoard::Print() {
    std::string W = "\033[0m";  // white (normal)
    std::string R = "\033[31m";  // red
    std::string G = "\033[32m";  // green
    std::string B = "\033[34m";  // blue

    std::cout << "┌───┬───┬───" << B << "╥" << W << "───┬───┬───" << B << "╥" << W << "───┬───┬───┐" << std::endl;
    for (int i = 0; i < 9; i++) {
        std::cout << "│";
        for (int j = 0; j < 9; j++) {
            std::string value = " ";
            if (givenValues[i][j] > 0) {
                value = G + std::to_string(givenValues[i][j]) + W;
            } else if (playerValues[i][j] > 0) {
                value = R + std::to_string(playerValues[i][j]) + W;
            }

            std::string terminator = ((j + 1) % 3 == 0 && j < 8 && j != 0) ? B + "║" + W : "│";
            std::cout << " " << value << " " << terminator;
            if (j >= 8) {
                std::cout << std::endl;
            }
        }
        if (i < 8) {
            if ((i + 1) % 3 == 0) {
                std::cout << B << "╞═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╡" << W << std::endl;
            } else {
                std::cout << "├───┼───┼───" << B << "╫" << W << "───┼───┼───" << B << "╫" << W << "───┼───┼───┤" << std::endl;
            }
        }
    }
    std::cout << "└───┴───┴───" << B << "╨" << W << "───┴───┴───" << B << "╨" << W << "───┴───┴───┘" << std::endl;
}