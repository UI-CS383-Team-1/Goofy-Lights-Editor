#include "grid.h"

Grid::Grid()
{
    rows = 10;
    columns = 20;
    //Default Allocation with size 10 * 20
     cellColors = new QColor*[rows];
     for(int i = 0; i < rows; ++i)
     {
         cellColors[i] = new QColor[columns];
     }
    defaultColor = QColor(0,0,0);//(187,187,187);  //set default color to grey
    setAllCellColor(defaultColor);
}

Grid::Grid(QColor color)
{
    rows = 10;
    columns = 20;
    //Default Allocation with size 10 * 20
    cellColors = new QColor*[rows];
    for(int i = 0; i < rows; ++i)
    {
        cellColors[i] = new QColor[columns];
    }
    defaultColor = color;
    setAllCellColor(color);
}

Grid::Grid(int rowCount, int columnCount)
{
    rows = rowCount;
    columns = columnCount;
    cellColors = new QColor*[rows];
    for(int i = 0; i < rows; ++i)
    {
        cellColors[i] = new QColor[columns];
    }
    defaultColor = QColor(0,0,0);//(187,187,187);  //set default color to grey
    setAllCellColor(defaultColor);
}

Grid::Grid(int rowCount, int columnCount, QColor color)
{
    rows = rowCount;
    columns = columnCount;
    cellColors = new QColor*[rows];
    for(int i = 0; i < rows; ++i)
    {
        cellColors[i] = new QColor[columns];
    }
    defaultColor = color;
    setAllCellColor(color);
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

void Grid::setCellColor(QColor color,int rowIndex, int columnIndex)
{
    if (rowIndex >= 0 && rowIndex < rows && columnIndex >= 0 && columnIndex < columns)
    {
        cellColors[rowIndex][columnIndex] = color;
    }
    else
    {
        std::cout<<"Set cell color accepts rowIdex 0-"<<rows-1<<" and columnIndex 0-"<<columns-1<<std::endl;

    }

}

QColor Grid::getCellColor(int rowIndex,int columnIndex)
{
    if (rowIndex >= 0 && rowIndex < rows && columnIndex >= 0 && columnIndex < columns)
    {
        return cellColors[rowIndex][columnIndex];
    }
    else
    {
        std::cout<<"Set cell color accepts rowIdex 0-"<<rows-1<<" and columnIndex 0-"<<columns-1<<std::endl;
        return defaultColor;

    }
}

void Grid::setAllCellColor(QColor color)
{
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            cellColors[i][j] = color;
        }
    }
}

void Grid::setTime(unsigned long t){
    time = t;
}

unsigned long Grid::getTime(){
    return time;
}






