// Cells.cpp

#include "Cells.h"
#include <cmath>

Cells::Cells(int size): size(size) {
    cells = new int*[size];  // Allocate array of pointers
    for (int i = 0; i < size; ++i) {
        cells[i] = new int[size];  // Allocate array of integers for each pointer
    }
}

Cells::~Cells() {
    for (int i = 0; i < size; ++i) {
        delete[] cells[i];  // Deallocate each sub-array
    }
    delete[] cells;  // Deallocate array of pointers
}

/**
 * Set values of all cells based on the 2d array provided
 * @param values 2d array of values
 */
void Cells::setValues(int** values) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            setValue(i, j, values[i][j]);
        }
    }
}

// Function definitions
void Cells::setValue(int x, int y, int value) {
    if (x >= 0 && x < size && y >= 0 && y < size) {
        cells[x][y] = value;
    }
    // Here you might want to add error handling for out-of-bounds indices
}

int Cells::getValue(int x, int y) const {
    if (x >= 0 && x < size && y >= 0 && y < size) {
        return cells[x][y];
    }
    // Here you might want to add error handling for out-of-bounds indices or return a default value
    return -1; // For the sake of this example, we'll return -1 as an error code
}

// check whether the value is out of bound
bool Cells::isOutOfBounds(int value) const{
    return value < 1 || value > size;
}

/**
 * Check whether the values in the cells provided is valid.
 * This proccess can be broken down into checking each row, each column, and each 3x3 square
 * @return boolean of whether cells is valid
 */
bool Cells::isValid() const{
    return isAllRowsValid() && isAllColsValid() && isAllSquaresValid();
}

bool Cells::isAllRowsValid() const{
    for(int i = 0; i < size; i++){
        if(!isRowValid(i)){
            return false;
        }
    }
    return true;
}

bool Cells::isAllColsValid() const{
    for(int i = 0; i < size; i++){
        if(!isColValid(i)){
            return false;
        }
    }
    return true;
}

bool Cells::isAllSquaresValid() const{
    for(int i = 0; i < size; i++){
        if(!isSquareValid(i)){
            return false;
        }
    }
    return true;
}

/**
 * Check whether the values in the row provided is valid.
 * Valid row is a row that only has unique values
 * @param rowNo row number to be checked (strating from 0 from top)
 * @return boolean of whether the row is valid
 */
bool Cells::isRowValid(int rowNo) const{
    // get a list of boolean of whether a number has been found.
    // Note: +1 because sudoku number starts from 1
    bool found[size+1];
    for(int i = 0; i < size+1; i++){
        found[i] = false;
    }

    for(int i = 0; i < size; i++){
        int value = getValue(rowNo, i);
        if(found[value] || isOutOfBounds(value)){
            return false;
        }
        found[value] = true;
    }
    return true;
}

bool Cells::isColValid(int colNo) const{
    // get a list of boolean of whether a number has been found.
    // Note: +1 because sudoku number starts from 1
    bool found[size+1];
    for(int i = 0; i < size+1; i++){
        found[i] = false;
    }

    for(int i = 0; i < size; i++){
        int value = getValue(i, colNo);
        if(found[value] || isOutOfBounds(value)){
            return false;
        }
        found[value] = true;
    }
    return true;
}

/**
 * Square is defined as a sqrt(size)xsqrt(size) cells
 * @param squareNo start from 0 from top left and end at size-1 in bottom right.
 * As example size=9 would look like:
 * 0, 1, 2
 * 3, 4, 5
 * 6, 7, 8
 * @return boolean of whether the cells is valid
 */
bool Cells::isSquareValid(int squareNo) const{
    // get a list of boolean of whether a number has been found.
    // Note: +1 because sudoku number starts from 1
    bool found[size+1];
    for(int i = 0; i < size+1; i++){
        found[i] = false;
    }

    int squareSize = sqrt(size);
    int rowStart = (squareNo / squareSize) * squareSize;
    int colStart = (squareNo % squareSize) * squareSize;
    for(int i = rowStart; i < rowStart + squareSize; i++){
        for(int j = colStart; j < colStart + squareSize; j++){
            int value = getValue(i, j);
            if(found[value] || isOutOfBounds(value)){
                return false;
            }
            found[value] = true;
        }
    }
    return true;
}