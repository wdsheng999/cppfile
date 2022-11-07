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
Grid<char> Animation(Grid<char> gird);//clear and show each step
Grid<char> Animation_w(Grid<char> grid);

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
        while(1)
        {
            string step=getLine("a)nimate, t)ick, q)uit?");
            if(step=="q" || step=="Q"){
                cout << "Have a nice Life!" << endl;
                return 0;
            }
            else if(step=="t" || step=="T"){
                Grid<char> next_life=NextState(life);
                life=next_life;
                ShowGrid(life);
            }
            else if(step=="a" || step=="A"){
                life=Animation(life);
            }
            else{
                cout<<"input wrong, please follow the guidance"<<endl;
                continue;
            }
        }

    }
    else if(wrap=="y")
    {
        while(1)
        {
            string step=getLine("a)nimate, t)ick, q)uit?");
            if(step=="q" || step=="Q"){
                cout << "Have a nice Life!" << endl;
                return 0;
            }
            else if(step=="t" || step=="T"){
                Grid<char> next_life=NextState_w(life);
                life=next_life;
                ShowGrid(life);
            }
            else if(step=="a" || step=="A"){
                life=Animation_w(life);
            }
            else{
                cout<<"input wrong, please follow the guidance"<<endl;
                continue;
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
    //string str=grid.toString2D();
    //cout<<str<<endl;
    for(int i=0;i<grid.numRows();i++)
    {
        for(int j=0;j<grid.numCols();j++)
        {
            cout<<grid[i][j];
        }
        cout<<endl;
    }
}

Grid<char> ReadInput(int &row, int &col)
{
    string name=getLine("Grid input file name? ");
    while (!fileExists(name)) {
        cout<<"Unable to open that file. Try again."<<endl;
        name="";
        name=getLine("Grid input file name? ");
        if(fileExists(name)) break;//this is my input precaucious
    }
    /*string name=getLine("Grid input file name? ");
    do{

        if(!fileExists(name)) cout<<"No such file, please check!"<<endl;
        string name=getLine("Grid input file name? ");
    }while (!fileExists(name));*/

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

Grid<char> Animation(Grid<char> grid){
    string time_str=getLine("How many frames?");
    while(!stringIsInteger(time_str))
    {
        cout<<"Illegal integer format. Try again."<<endl;
        time_str="";
        time_str=getLine("How many frames?");
        if(stringIsInteger(time_str)) break;
    }

    int times=stringToInteger(time_str);
    int n_cols=grid.numCols();
    int n_rows=grid.numRows();
    Grid<char> tmp_grid(n_rows,n_cols);
    for (int  var = 0;  var< times; var++) {
        tmp_grid=NextState(grid);
        grid=tmp_grid;
        ShowGrid(grid);
        pause(1000);
        clearConsole();
    }
    ShowGrid(grid);

    return grid;
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
            for(int x=i-1;x<=i+1;x++)
            {
                /*
                (i-1, j-1)(i-1, j)(i-1,j+1)
                (i, j-1)  (i, j)  (i, j+1)
                (i+1,j-1) (i+1,j) (i+1,j+1)
                */
                for(int y=j-1;y<=j+1;y++)
                {
                    //wraping using a math function
                    if(grid.inBounds(x,y)){
                        if(checkState(grid[x][y]))
                            state=state+1;
                    }
                    else{
                        x=(x+n_rows)%n_rows;
                        y=(y+n_cols)%n_cols;
                        if(checkState(grid[x][y]))
                            state=state+1;
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
Grid<char> Animation_w(Grid<char> grid){
    string time_str=getLine("How many frames?");
    while(!stringIsInteger(time_str))
    {
        cout<<"Illegal integer format. Try again."<<endl;
        time_str="";
        time_str=getLine("How many frames?");
        if(stringIsInteger(time_str)) break;
    }
    int times=stringToInteger(time_str);
    int n_cols=grid.numCols();
    int n_rows=grid.numRows();
    Grid<char> tmp_grid(n_rows,n_cols);
    for (int  var = 0;  var< times; var++) {
        tmp_grid=NextState_w(grid);
        grid=tmp_grid;
        ShowGrid(grid);
        pause(1000);
        clearConsole();
    }
    ShowGrid(grid);

    return grid;
}
