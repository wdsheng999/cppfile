#include<iostream>
#include"console.h"
#include "grid.h"
using namespace std;

const string DRINK_TYPE = "coke";

void bottles(int count){
    cout<<count<<"bottles of "<<DRINK_TYPE<<"."<<endl;
    cout<<"take one down, pass it around" \
       <<(count-1)<<"bottles of"<< DRINK_TYPE\
      <<"on the wall."<<endl<<endl;

}

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

int main(){
    for (int i=99;i>0;i--){
        bottles(i);
    }
    Grid<int> grid(2,2);
    printGrid(grid);
    return 0;
}
