#include <string>
#include "robot.h"
#include "queue.h"

int main()
{
    Queue<Robot> wline;
    Queue<Robot> oline;
    Queue<Robot> pline;
    Queue<Robot> mline;
    string input;
    bool on=1;
    while(on)
    {
        cin>>input; 
        if(input=="$")
            on=0;
        else
        {
            Robot R;
            cin>>input;
            for(int i=0;i<atoi(input.c_str());i++)
            {
                cin>>input;
                R.add(input); 
            }
            
        }
    }
    
    
    return 0;
}
