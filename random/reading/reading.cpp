#include "reading.h"

int main()
{
	ifstream in;
	ofstream out;
	string sent;

	in.open("input.dat");
	int n=0;
	while ( getline (in,sent) )
	{
		cout << sent << " " << n << endl;
		n++;

	}
	in.close();

}