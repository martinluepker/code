/*
Martin Luepker
12/3/15
G
linear search
*/

#include <iostream>
//#include "list.h"
#include "list.cpp"
using namespace std;

int main()
{
	bool quit=0;
	int input;
	list<int> li;
	list<char> lc;	
	
	while(quit==0)
	{
		cout<<"Welcome to the linear search app. What would you like to do?"<<endl
			<<"1. Search for an integer in a list"<<endl
			<<"2. Search for a character in a list"<<endl
			<<"3. Quit"<<endl;
		cin>>input;
		switch(input)
		{
			case 1:
							
				cout<<"Enter The List of 5 characters"<<endl;
				int ini;
				for(int i=0;i<5;i++)
				{
					cin>>ini;
					li.insert(ini,i);
				}
				cout<<"Enter the item to be searched"<<endl;
				cin>>ini;
				cout<<"The item is";
				li.search(ini)?cout<<" ":cout<<" not ";
				cout<<"in the list"<<endl;
				break;
			case 2:
				cout<<"Enter The List of 5 characters"<<endl;
				char inc;
				for(int i=0;i<5;i++)
				{
					cin>>inc;
					lc.insert(inc,i);
				}
				cout<<"Enter the item to be searched"<<endl;
				cin>>inc;
				cout<<"The item is";
				lc.search(inc)?cout<<" ":cout<<" not ";
				cout<<"in the list"<<endl;
				break;
			case 3:
				quit=1;
				break;
			default:
				cout<<"Invalid input"<<endl;
		}
		cout<<endl;
	}
	return 0;
}