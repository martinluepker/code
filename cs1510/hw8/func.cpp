#include "func.h"

bool SolveMaze(int row, int col,Maze& m) 
{
    if(row==m.g_row &&col==m.g_col) 
        return true; 
   
    if(isSafe(row,col,m))
    {
        m.col.push(col);
        m.row.push(row);
        if(SolveMaze(row-1,col, m)) 
            return true; 
        if(SolveMaze(row,col+1,m))
            return true; 
        if(SolveMaze(row+1,col,m)) 
            return true;
        if(SolveMaze(row,col-1,m))
            return true;
        m.col.pop();
        m.row.pop();
        return false; 
    }
    return false; 
}

bool isSafe(int row, int col,Maze& m)
{
    bool past=0;
    for(int i=0;i<m.row.getSize();i++)
        if(row==m.row[i]&&col==m.col[i])
            past=1;
            
    if(m.space[row][col]=='#'
     ||m.space[row][col]=='T'
     ||past)
        return 0;
    else 
        return 1;        
       
}
