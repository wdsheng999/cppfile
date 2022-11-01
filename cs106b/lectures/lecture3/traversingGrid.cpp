#include<iostream>
#include "grid.h"
using namespace std;

void printGrid(Grid<int> &grid)
{
    for (int r=0;r<grid.numRows();r++)
    {
        for (int c=0;r<grid.numCols();c++)
        {
            cout<<grid[r][c]<<endl;
        }
    }
}

int main()
{
    Grid<int> grid(2,2);
    printGrid(grid);
    return 0;
}