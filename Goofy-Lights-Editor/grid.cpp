#include "grid.h"

Grid::Grid()
{
    rows = 10;
    columns = 20;
}

Grid::Grid(int rowCount, int columnCount)
{
    rows = rowCount;
    columns = columnCount;
}

void Grid::setGridRowCount(int rowCount)
{
    rows = rowCount;
}

void Grid::setGridColumnCount(int columnCount)
{
    columns = columnCount;
}

int Grid::getGridRowCount()
{
    return rows;
}

int Grid::getGridColumnCount()
{
    return columns;
}
