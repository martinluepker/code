/*
Martin Luepker
12/9/15
G
fizzbuzz
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	//part 1
	cout<<"The solution to the FizzBuzz test is:"<<endl;
	const int lastnum=100;
	for(int i=1;i<=100;i++)
	{
		if(i%3==0&&i%5==0)
			cout<<"FizzBuzz"<<endl;
		else if(i%3==0)
			cout<<"Fizz"<<endl;
		else if(i%5==0)
			cout<<"Buzz"<<endl;
		else
			cout<<i<<endl;
	}
	
	//part 2
	
	const int dest=200;
	cout<<"The smallest number of moves to get to exactly "<<dest<<" is:"<<endl;
	int n=0;
	int num=dest;
	while(1<num)
	{
		while(num%2==0)
		{
			num/=2;
			n++;
		}
		num--;
		n++;
	}
	n--;
	cout<<n<<endl;

	return 0;
}