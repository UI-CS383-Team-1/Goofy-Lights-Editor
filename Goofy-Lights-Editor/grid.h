#ifndef GRID_H
#define GRID_H
#include <QColor>
#include <iostream>

class Grid
{
public:
    Grid();
    Grid(QColor);
    Grid(int,int);
    Grid(int, int, QColor);
    void setGridRowCount(int);
    void setGridColumnCount(int);
    int getGridRowCount();
    int getGridColumnCount();
    void setCellColor(QColor,int,int);
    QColor getCellColor(int,int);
    void setAllCellColor(QColor);
    QColor **cellColors;

private:
    int rows;
    int columns;
    QColor defaultColor;
    unsigned long time;
};

#endif // GRID_H
