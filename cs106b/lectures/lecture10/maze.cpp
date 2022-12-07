#include "grid.h"
#include <string>
#include<iostream>
using namespace std;
bool solveMazeRecur(int rol, int col, Grid<char> &maze)
{
    if (maze[rol][col] == 'X')
    {
        return false;
    }

    if (maze[rol][col] == '.')
    {
        return false;
    }

    if (maze[rol][col] == 'F')
    {
        return true;
    }
    maze[rol][col] = '.';

    // recurse call solveMazeRecursivePrint(row,col)
    // N--E--S--W, if one of the pos is true, return true

    // if north
    if (solveMazeRecur(rol - 1, col, maze) == true)
    {
        return true;
    }
    // if east
    if (solveMazeRecur(rol, col + 1, maze) == true)
    {
        return true;
    }
    // if south
    if (solveMazeRecur(rol + 1, col, maze) == true)
    {
        return true;
    }
    // if west
    if (solveMazeRecur(rol, col - 1, maze) == true)
    {
        return true;
    }

    // if none, mark b
    maze[rol][col] = 'b';
    return false;
}



int main()
{
    Grid<char> maze64(8,8);
    string maze=
    "XXXXXXXXXXXXXXX\
    XS  X";
    cout<<maze<<endl;
    return 0;
}