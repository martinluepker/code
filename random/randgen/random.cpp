#include <iostream> 
#include <math.h>
using namespace std;


template <typename t>
int nthnum(const t num,const int n)
{
	int length =log10(num)+1;
	int temp=num/pow(10,length-n);
	return(temp%10);
}

int main()
{
	float seed;
	int n;
	cout<<"Input Seed: ";
	cin>>seed;
	cout<<"Nth letter: ";
	cin>>n;
	
	
	
	return 0;
}
