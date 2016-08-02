//Martin Luepker
#include "func.h"
#include "stack.h"

int main()
{
    int cs,rs;
    Maze maze;
    bool on=1;
    int n=0;
    while(on)
    {
        //get size
        cin >> cs >> rs;
        cin.ignore(); 
        if(!cs&&!rs)
            on=0;
        else
        {
            //make space
            maze.space = new char*[rs];
            for(int k=0; k < rs; k++)
                maze.space[k] = new char[cs+1]; 
            
            //input
            for(int k=0; k < rs; k++)
                cin.getline(maze.space[k], cs+1); 
           =
            //make maze
            for(int i=0;i<rs;i++)
            {
                for(int j=0;j<cs;j++)
                {
                    if(maze.space[i][j]=='B')
                    {
                        maze.s_row=i;
                        maze.s_col=j;
                    }
                    if(maze.space[i][j]=='E')
                    {
                        maze.g_row=i;
                        maze.g_col=j;
                    }
                }
            }
            
            SolveMaze(maze.s_row,maze.s_col,maze);

            while(!maze.row.isEmpty())
            {
                maze.space[maze.row.top()][maze.col.top()]='.';
                maze.row.pop();
                maze.col.pop();
            }
            
            //output 
            cout<<endl<<"Map : "<<n<<endl;
            for(int k=0; k < rs; k++)
                cout << maze.space[k] << endl; 
            n++;
            
            //delete space    
            for(int k=0; k < rs; k++)   
                delete [] maze.space[k]; 
            delete [] maze.space;
        }
    }
    return 0;
}