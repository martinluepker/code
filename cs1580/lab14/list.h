/*
Martin Luepker
12/3/15
G
linear search
*/

#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;


template <class T>
class list
{
	private:
		static const int arraylen=5;
		T array[arraylen];
	public:
		void insert(T,int);
		bool search(T) const;
};

#endif
