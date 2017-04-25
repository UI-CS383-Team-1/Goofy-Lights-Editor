#ifndef GRID_H
#define GRID_H
#include <QColor>
#include <iostream>

class Grid
{
public:

    //Creates a new grid of size 10x20 with a default color gray
    Grid();

    //Creates a new grid of size 10x20 with a given color
    Grid(QColor);

    //Creates a new grid of size row x column with a default color gray
    Grid(int, int);

    //Creates a new grid of size row x column with a given color
    Grid(int, int, QColor);

    //Creates tower grid
    Grid(int, int, int, int);

    //Sets the number of rows to a given value
    void setGridRowCount(int);

    //Sets the number of columns to a given value
    void setGridColumnCount(int);

    //Returns the number of rows
    int getGridRowCount();

    //Returns the number of columns
    int getGridColumnCount();

    //Sets a cell at (row, column) to a given color
    void setCellColor(QColor,int,int);

    //Returns the color at (row, column)
    QColor getCellColor(int,int);

    //Sets all cells in the grid to a given color
    void setAllCellColor(QColor);

    //Sets the tower grid values
    void setTowerGrid(int,int,int,int);

    //Returns tower grid value start row
    int getTowerGridStartRow();

    //Returns tower grid value end row
    int getTowerGridEndRow();

    //Returns tower grid value start column
    int getTowerGridStartCol();

    //Returns tower grid value end column
    int getTowerGridEndCol();

    //Sets the time to a given value
    void setTime(unsigned long);

    //Returns the time
    unsigned long getTime();

    //2d array for the grid colors
    QColor **cellColors;

    int gridCellStartRow;
    int gridCellStartCol;
    int gridCellEndRow;
    int gridCellEndCol;

private:
    int rows;
    int columns;
    QColor defaultColor;
    unsigned long time;
};

#endif // GRID_H
