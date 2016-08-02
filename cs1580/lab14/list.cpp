/*
Martin Luepker
12/3/15
G
linear search
*/

#include <iostream>
#include "list.h"
using namespace std;

template <class T>
void list<T>::insert(T in,int n)
{
	array[n]=in;
	return;
}

template <class T>
bool list<T>::search(T in) const
{
	bool isin=0;
	for(int i=0;i<arraylen;i++)
	{
		if(array[i]==in)
			isin=1;
	}
	return isin;
}
