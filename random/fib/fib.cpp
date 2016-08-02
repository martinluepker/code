#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    long p=1;//previous
    long n=1;//new
    int i=0;//counter
    
    while (i<1000) {
        p=n;
        n=p+n;
        cout << n<<",";
        i++;
    }
}