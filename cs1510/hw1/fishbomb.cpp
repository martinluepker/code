#include<iostream>
#include<math.h>
using namespace std;

struct point
{
    int w;
    int h; 
    int value;
};

int main()
{
    const int radius=3;
    int cases,height,width;
    int **water;    
    cin>>cases;
    for(int n=0;n<cases;n++)
    {
        cin>>width>>height;
        
        //create water
        water = new	int *[height];
        for(int i=0;i<height;i++)	
            water[i] = new int[width];
        
        //fill water
        
        for(int h=0;h<height;h++)
        {
            for(int w=0;w<width;w++)
            {
               cin>>water[h][w];
            }
        }
        
        point max={0,0,0};
        int current=0;
       
        //count fish
        for(int h=1;h<height-1;h++)
        {
            for(int w=1;w<width-1;w++)
            {
                current=0;
                for(int i=0;i<pow(radius,2);i++)
                {
                    current+=water[h+i/3-1][w+i%radius-1];
                }
  
                if (current>max.value)
                {
                    max.w=w;
                    max.h=h;
                    max.value=current;
                }
            }
        }
        cout<<"#"<<n<<": ("<<max.w<<","<<max.h<<") "<<max.value<<endl;    
        
        //delete water
        for(int i=0;i<height;i++)
            delete water[i];
        delete [] water;
          
               
    }
    return 0;
}