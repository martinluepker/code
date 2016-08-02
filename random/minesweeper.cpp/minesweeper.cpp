#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

struct spot
{
	bool bomb;
	float adj;
	spot():bomb(0),adj(0){}
};

int main()
{
	srand(time(NULL));
	const int height=30;
	const int width=16;
	const int mines=99;
	const int time=500;
	const int area=width*height;
	ofstream fout; 
	int count=0;
	
	fout.open("output");
	
	//makes float precision fixed
	fout.setf (ios::fixed,ios::floatfield);
	fout.precision(4);
	
	spot ave[area];
	for(int n=0;n<time;n++)
	{
		spot minespace[area];
		int minecount=0;
		while(minecount<mines)
		{
			int num=rand()%area;
			if(minespace[num].bomb==0)
			{
				minespace[num].bomb=1;
				minecount++;
			}
		}
		
		for(int i=0;i<area;i++)
		{
			if(minespace[i].bomb==1)
			{
				//bottom row 
				if(i/width==0)
				{
					//bottom left corner
					if(i%width==0)
					{
						minespace[i+1].adj++;
						minespace[i+width].adj++;
						minespace[i+width+1].adj++;
					}
					//bottom right coner
					else if(i%width==width-1)
					{
						minespace[i-1].adj++;
						minespace[i+width].adj++;
						minespace[i+width-1].adj++;
					}
					//rest of bottom
					else
					{
						minespace[i-1].adj++;
						minespace[i+1].adj++;
						minespace[i+width].adj++;
						minespace[i+width-1].adj++;
						minespace[i+width+1].adj++;
					}
				}
				//top row 
				else if(i/width==height-1)
				{
					//top left corner
					if(i%width==0)
					{
					minespace[i+1].adj++;
					minespace[i-width].adj++;
					minespace[i-width+1].adj++;	
					}
					//top right corner
					else if(i%width==width-1)
					{
						minespace[i-1].adj++;
						minespace[i-width].adj++;
						minespace[i-width-1].adj++;
					}
					//rest of top
					else
					{
						minespace[i-1].adj++;
						minespace[i+1].adj++;
						minespace[i-width].adj++;
						minespace[i-width-1].adj++;
						minespace[i-width+1].adj++;
					}
				}
				//left column
				else if(i%width==0)
				{
					minespace[i+1].adj++;
					minespace[i+width].adj++;
					minespace[i-width].adj++;
					minespace[i+width+1].adj++;
					minespace[i-width+1].adj++;
				}
				//right column
				else if(i%width==width-1)
				{
					minespace[i-1].adj++;
					minespace[i+width].adj++;
					minespace[i-width].adj++;
					minespace[i+width-1].adj++;
					minespace[i-width-1].adj++;
				}
				else
				{
					minespace[i-width-1].adj++;
					minespace[i-width].adj++;
					minespace[i-width+1].adj++;
					minespace[i-1].adj++;
					minespace[i+1].adj++;
					minespace[i+width-1].adj++;
					minespace[i+width].adj++;
					minespace[i+width+1].adj++;
				}
			}
		}
		
		for(int i=0;i<area;i++)
		{
			ave[i].adj+=minespace[i].adj;
			if(minespace[i].bomb!=1&&minespace[i].adj==0)
				count++;
		}
		/*
		for(int i=0;i<area;i++)
		{
			if(minespace[i].bomb==1)
				fout<<"* ";
			else 
				fout<<minespace[i].adj<<" ";
			if(i%width==width-1)
				fout<<endl;
		}
		fout<<endl;
		*/
	}
	
	for(int i=0;i<area;i++)
	{
		ave[i].adj/=time;
		fout<<ave[i].adj<<" ";
		if(i%width==width-1)
			fout<<endl;
	}
	fout<<endl;
	
	float average=static_cast<float>(count)/time;
	fout<<"Average number of 0's is "<<average<<endl;
	fout<<"Which is "<<100*average/area<<"% of the total area"<<endl;
	fout.close();
	return 0;
}