/*
Martin Luepker
11/18/15
G
opperator overloading
*/

#include "lab13.h"
bool menuon=1;
int main()
{
	box b1;
	box b2;
	box b3;
	while(menuon)
	{
		cout<<"Welcome to the Box adder"<<endl;
		cout<<"\t1. Add two boxes"<<endl;
		cout<<"\t2. Exit"<<endl;
		int input;
		cin>>input;
		switch(input)
		{
			case 1:
				takeinput(b1,1);
				takeinput(b2,2);
				b3=b1+b2;
				cout<<b3;
				break;
			case 2:
				menuon=0;
				cout<<"Thanks for using the Box Adder"<<endl;
				break;
			default:
				cout<<"invalid input";
				break;
		}
	}
	return 0;
}