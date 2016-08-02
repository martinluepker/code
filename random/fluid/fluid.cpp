#include<iostream>
#include<cmath>
using namespace std;
const int rad=200;
const int width=168;
const int height=48;


struct particle
{
        float x;
        float y;
        float vx;
        float vy;
        float ax;
        float ay;
        bool collision;
        bool stationary;
};

//class screen

int main()
{

    particle b={29.5,0,1,1,1,1,0,0};

    cout<<floor(b.x)<<endl;
    
    bool screen[2*rad][2*rad];
    return 0;

}

