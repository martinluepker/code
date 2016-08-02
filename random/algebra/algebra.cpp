#include <cmath>
#include <iostream>
#include <string.h>
using namespace std;


int main()
{
	string equ;
	cout<<"Enter an Equation or help for list of operators"<<endl;
	getline(cin,equ);
	char *equation=new char[equ.size()+1];
	equation[equ.size()]=0;
	memcpy(equation,equ.c_str(),equ.size());
}