#ifndef GRID_H
#define GRID_H


class Grid
{
public:
    Grid();
    Grid(int rowCount,int columnCount);
    void setGridRowCount(int rowCount);
    void setGridColumnCount(int columnCount);
    int getGridRowCount();
    int getGridColumnCount();

private:
    int rows;
    int columns;
};

#endif // GRID_H
