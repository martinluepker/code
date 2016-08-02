
#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include "stack.h"
using namespace std;



struct Maze
{
    char **space;
    int s_row,s_col,g_row,g_col;
    Stack<int> row,col;
};



bool SolveMaze(int row, int col,Maze& m);
bool isSafe(int row,int col,Maze& m);

#endif


