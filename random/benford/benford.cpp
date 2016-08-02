#include<iostream>
#include<math.h>
using namespace std;

float first(int );//outputs first number
int largest(int []);//finds which first number is most frequent


int main()
{
	const short MAX_LENGTH=50;
	int nums[10];
	int x=1;
	short biggest;
	int iter;
	
	cout<<"How many times should the equation be calculated? ";
	cin>>iter;
	for(short i=0;i<10;i++)
	{
		nums[i]=0;
	}	
	while(x<iter)
	{
		nums[static_cast<int>(first(x))]+=1;
		x++;
	}
	cout<<endl;
	biggest=largest(nums);
	for(int n=1;n<10;n++)
	{
		int length=MAX_LENGTH*(static_cast<float>(nums[n])/nums[biggest]);
		cout<<n<<": ";
		for(int i=0;i<length;i++)
		{
			cout<<"|";
		}
		cout<<static_cast<float>(nums[n])/iter*100<<"%"<<endl;
	}
	return 0;	
}


float first(int x)
{
	return floor(  pow(3,x)  /pow(10,floor(log10(  pow(3,x)  ))));
}


int largest(int a[])
{
	int big=0;
	for(int i=1;i<sizeof(a)/sizeof(int);i++)
	{
		if(a[i]>a[big])
		{
			big=i;
		}
	}
	return big;
}