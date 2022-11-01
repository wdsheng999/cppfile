#include <iostream>
#include "grid.h"
using namespace std;

void printGrid(Grid<int> &grid)
{
    for (int r=0;r<grid.numRows();r++)
    {
        for (int c=0;c<grid.numCols();c++)
        {
            cout<<grid[r][c]<<" ";
        }
        cout<<endl;
    }
}

void eyeGrid(Grid<int> &grid)
{
    int c=grid.numCols();
    int r=grid.numRows();
    if(c!=r) {
        cout<<"not a symmetric grid, exiting..."<<endl;
        grid.fill(4);
    }
    for (int i=0;i<c;i++) grid[i][i]=1;
}

int main()
{
    Grid<int> grid(2,2,1);
    grid.resize(2,2);
    printGrid(grid);
    cout<<"-------------eyeGrid---------------------"<<endl;
    eyeGrid(grid);
    printGrid(grid);
    return 0;
}
