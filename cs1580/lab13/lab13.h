/*
Martin Luepker
11/18/15
G
opperator overloading
*/

#ifndef LAB13_H
#define LAB13_H

#include <iostream>
using namespace std;

struct box
{
	int length;
	int width;
	int depth;
};

/*
desc:allows adding values of 2 box structs
pre: takes 2 box structs 
post: returns a box struct
*/
box operator +(const box&,const box&);
/*
desc:takes input for the values of a box
pre: takes a box and which number it is
post: sets the values of the box
*/
void takeinput(box& ,int );
/*
desc:allows printing the value of a box 
pre: takes a box stuct 
post: prints the values of the box struct 
*/
ostream& operator <<(ostream& outs, const box& b); 
#endif