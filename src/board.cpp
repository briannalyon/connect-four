/**
 * @file board.cpp
 * @author Josie Wicklund and Brianna Lyon
 * @brief 
 * @version 0.1
 * @date 2021-04-15
 */

#include "board.h"
//#include <SFML/Graphics.hpp>

Board::Board() {
    for (int row = 0; row < ROWSIZE; row++) {
        for (int col = 0; col < COLSIZE; col++) {
            board[row][col] = '*';
        }
    }
}

// USE SFML GRAPHICS IN HERE SOMEHOW
void Board::display() {
    cout << "  1 2 3 4 5 6 7" << endl;
    for (int row = 0; row < ROWSIZE; row++) {
        for (int col = 0; col < COLSIZE; col++) {
            cout << board[row][col] << ' ';
        }
         cout << endl;
    }
    cout << endl;
}

bool Board::placeToken(Coordinate coordinate, char tokenColor) {
    int row = coordinate.getRow(); // does the 
    int col = coordinate.getCol();

    if (!isInBounds(coordinate)) {
        return false;
    }

    if (!isClear(coordinate)) {
        return false;
    }
    board[row][col] = tokenColor;
    return true;
}

bool Board::isClear(Coordinate coordinate)
{
    int row = coordinate.getRow();
    int col = coordinate.getCol();

    if (board[row][col] != '*') {
        return false;
    }
    return true;
}

bool Board::isInBounds(Coordinate coordinate) {
    if (coordinate.getCol() > COLSIZE) {
        return false;
    } else if (coordinate.getRow() > ROWSIZE) {
        return false;
    }
    return true;
} 

bool Board::isEmpty(Coordinate coordinate) {
    int row = coordinate.getRow();
    int col = coordinate.getCol();

    if(board[row][col] == '*') {
        return true;
    }
    return false;
}

// USE SFML GRAPHICS IN HERE SOMEHOW
void Board::updateBoard(Coordinate coordinate, char tokenColor) {
    int row = coordinate.getRow();
    int col = coordinate.getCol();
    board[row][col] = tokenColor; 
}

char Board::getColor(Coordinate coordinate) {
    int row = coordinate.getRow();
    int col = coordinate.getCol();
    return board[row][col];
}

// char Board::getBoard(int row, int col) {
//     return board[row][col];
// }
void Board::randomizeCoordinate() {
    Coordinate coordinate;
    int col = 1 + rand() % 10;
    coordinate.set(col, findAvaiableRow(col));
}

bool Board::setCoordinate(char rowIn, int colIn) {
    Coordinate coordinate;
    int r = findAvaiableRow(colIn);
    int c = coordinate.convertCol(colIn);

    if (r == -1) {
        cout << "Invalid row character " << rowIn << endl;
        return false;
    }
    if (c == -1) {
        cout << "Invalid column value " << colIn << endl;
        return false;
    }
    coordinate.set(c,r);
    return true;
}

int Board::findAvaiableRow(int col) {
    for(int i = 0; i < COLSIZE; i++) {
        char symbol = board[i][col];
        if (symbol != '*') {
            return i - 1;
        }
    }
    return -1;
}

bool Board::fourConnected() {
    return false;
}
