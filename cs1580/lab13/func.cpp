/*
Martin Luepker
11/18/15
G
opperator overloading
*/

#include "lab13.h"

box operator +(const box& b1,const box& b2)
{
	box b3;
	b3.length=b1.length+b2.length;
	b3.width=b1.width+b2.width;
	b3.depth=b1.depth+b2.depth;
	return(b3);
}

void takeinput(box& b,int num)
{
	cout<<"Enter the length of box "<<num<<": ";
	cin>>b.length;
	cout<<"Enter the width of box "<<num<<": ";
	cin>>b.width;
	cout<<"Enter the depth of box "<<num<<": ";
	cin>>b.depth;
}

ostream& operator << (ostream& outs, const box& b) 
{
	cout<<"The dimensions of the new box are ("
		<<b.length<<","<<b.width<<","<<b.depth<<")"
		<<endl;

	return(outs);
}