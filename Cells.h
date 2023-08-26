//
// Created by alvin_janitra on 26/08/23.
//

#ifndef CODING_CELLS_H
#define CODING_CELLS_H

class Cells {
private:
    int** cells;
    int size;
public:
    Cells(int size);
    ~Cells();  // Destructor to deallocate memory

    void setValue(int x, int y, int value);
    int getValue(int x, int y) const;
    bool isValid() const;

    bool isRowValid(int rowNo) const;

    bool isColValid(int colNo) const;

    bool isSquareValid(int squareNo) const;

    bool isAllRowsValid() const;

    bool isAllColsValid() const;

    bool isAllSquaresValid() const;

    void setValues(int **values);

    bool isOutOfBounds(int value) const;
};


#endif //CODING_CELLS_H
