// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own.
// TODO: remove this comment header!

#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "console.h"
#include "filelib.h"
#include "grid.h"
#include "gwindow.h"
#include "simpio.h"
#include "strlib.h"
#include "lifegui.h"
using namespace std;

void Hellomessage(void);
Grid<char> ReadInput(int &row, int &col);
void ShowGrid(Grid<char> grid);
Grid<char> NextState(Grid<char> grid);
bool checkState(char x);//check the grid is alive or not
Grid<char> NextState_w(Grid<char> grid);//wrapping

/*-------------main--------------*/
int main() {
    // TODO: Finish the program!
    Hellomessage();
    int row=0;
    int col=0;
    Grid<char> life = ReadInput(row,col);
    string wrap = getLine("Should the simulation wrap around the grid?");
    ShowGrid(life);
    if(wrap=="n")
    {
        string step=getLine("a)nimate, t)ick, q)uit?");
        if(step=="q"){
            cout << "Have a nice Life!" << endl;
            return 0;
        }
        while(step=="t"){
            Grid<char> next_life=NextState(life);
            life=next_life;
            ShowGrid(life);
            string step=getLine("a)nimate, t)ick, q)uit?");
            if(step=="q"){
                cout << "Have a nice Life!" << endl;
                return 0;
            }
        }
    }

//    cout << "Have a nice Life!" << endl;
    return 0;
}
//--------------member---------------
void ShowGrid(Grid<char> grid)
{
    //cout<<"this is the grid print result"<<endl;
    string str=grid.toString2D();
    cout<<str<<endl;
}

Grid<char> ReadInput(int &row, int &col)
{
    string name=getLine("Grid input file name? ");
    while (!fileExists(name)) {
        cout<<"No such file, please check!"<<endl;
        string name=getLine("Grid input file name? ");
        if(fileExists(name)) break;//this is my input precaucious
    }
    ifstream inputfile;
    openFile(inputfile,name);
    //get first line, that is the row num
    string linestring;
    getline(inputfile,linestring);
    row=stringToInteger(linestring);
    getline(inputfile,linestring);
    col=stringToInteger(linestring);
    //grid initialization
    Grid<char> life(row,col);
    //loop grid
    for(int i=0;i<row;i++)
    {
        //read a line
        string linestring;
        getline(inputfile,linestring);
        //for elements in line, give a loop each
        for(int j=0;j<col;j++)
        {
            life[i][j]=linestring[j];
        }
    }
    return life;
}

void Hellomessage(void)
{
    cout<<"welcome to Game Life!"<<endl;
    cout<<"a simulation of the lifecycle of a bacteraia colony"<<endl;
    cout<<"Cells live and die by the following rules"<<endl;
    cout<<"-A cell with 1 or fewer neighbors dies"<<endl;
    cout<<"-Location with 2 neighbors live stable"<<endl;
    cout<<"-Location with 3 neighbors will create life"<<endl;
    cout<<"-A cell with 4 or more neighbors dies"<<endl;
    cout<<endl;
}

Grid<char> NextState(Grid<char> grid){
    int n_cols=grid.numCols();
    int n_rows=grid.numRows();

    Grid<char> tempGrid(n_rows,n_cols);
    //loop element, each same criterion
    for(int i=0;i<n_rows;i++)
    {
        for(int j=0;j<n_cols;j++)
        {
            //using inBound
            int state=0;
            for(int x=i-1;x<=i+1;x++)
            {
                /*
                (i-1, j-1)(i-1, j)(i-1,j+1)
                (i, j-1)  (i, j)  (i, j+1)
                (i+1,j-1) (i+1,j) (i+1,j+1)
                */
                for(int y=j-1;y<=j+1;y++)
                {
                    //out of bound
                    if(grid.inBounds(x,y)){
                        if(checkState(grid[x][y]))
                            state=state+1;//state is correct,but cannot pass to the switch
                    }
                }     
            }
            if(checkState(grid[i][j])) state=state-1;
            switch(state)
            {
                case 2: tempGrid[i][j]=grid[i][j];break;
                case 3: tempGrid[i][j]='X';break;
                default: tempGrid[i][j]='-';
            }
        }
    }
    return tempGrid;
}

bool checkState(char x)
{
    if(x=='X') return 1;
    else if (x=='-') return 0;
    else{
        cout<<"invalid grid, exit with -1"<<endl;
        return -1;
    }
}

Grid<char> NextState_w(Grid<char> grid){
    int n_cols=grid.numCols();
    int n_rows=grid.numRows();
    int state=0;
    Grid<char> tempGrid(n_rows,n_cols);
    //loop element, each same criterion
    for(int i=0;i<n_rows;i++)
    {
        for(int j=0;j<n_cols;j++)
        {
            //using inBound
            for(int x=i-1;x<i+1;x++)
            {
                /*
                (i-1, j-1)(i-1, j)(i-1,j+1)
                (i, j-1)  (i, j)  (i, j+1)
                (i+1,j-1) (i+1,j) (i+1,j+1)
                */
                for(int y=j-1;y<j+1;y++)
                {
                    //out of bound
                    if(grid.inBounds(x,y)){
                        if(checkState(grid[x][y]))
                            state=state+1;
                    }
                }
            }
            if(checkState(grid[i][j])) state=state-1;
            switch(state)
            {
                case 2: continue;
                case 3: tempGrid[i][j]='X';
                default: tempGrid[i][j]='-';
            }
        }
    }
    return tempGrid;
}
