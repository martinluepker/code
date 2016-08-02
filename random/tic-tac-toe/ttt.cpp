#include <cmath>
#include <iostream>
using namespace std;



ostream& operator << (ostream& , int []); 
const int size=9;
const int MAXX=5;
const int MAXO=4;

int main()
{
	int impossible=0;
	int cats=0;
	int xwin=0;
	int owin=0;
	int unfin=0;
	int n=0;
	int board[size]={0};
	while(n<=pow(3,9)-1)//-1 to not start over
	{
		int x=0;
		int o=0;
		//count pieces 
		for(int i=0;i<size;i++)
		{
			if(board[i]==1)
				x++;
			else if(board[i]==2)
				o++;
		}
		
		bool impos=0;
		//too many pieces 
		if(o>MAXO||x>MAXX||x-o>1||x-o<0)
		{
			impos=1;
			impossible++;
		}
		bool winx=0;
		bool wino=0;
		if(!impos)
		{
			for(int i=0;i<3;i++)
			{
				//horizontal 
				if(board[3*i+0]==1&&board[3*i+1]==1&&board[3*i+2]==1)
					winx=1;
				if(board[3*i+0]==2&&board[3*i+1]==2&&board[3*i+2]==2)
					wino=1;
				//vertical
				if(board[i]==1&&board[i+3]==1&&board[i+6]==1)
					winx=1;
				if(board[i]==2&&board[i+3]==2&&board[i+6]==2)
					wino=1;
			}
			//diagonals
			if(board[0]==1&&board[4]==1&&board[8]==1)
				winx=1;
			if(board[2]==1&&board[4]==1&&board[6]==1)
				winx=1;
			if(board[0]==2&&board[4]==2&&board[8]==2)
				wino=1;
			if(board[2]==2&&board[4]==2&&board[6]==2)
				wino=1;
			
			if(wino&&winx)
				impossible++;
			else if(winx)
				xwin++;
			else if(wino)
				owin++;
			else if(o+x==size)
				cats++;
			else	
			{	
				unfin++;
			}
		}	
		board[0]++;
		for(int i=0;i<size-1;i++)
			if(board[i]>=3)
			{
				board[i+1]++;
				board[i]=0;
			}
		if (board[size-1]>=3)
		{
			board[0]++;
			board[size-1]=0;
		}
		n++;
	}
	cout<<n-impossible<<" possible boards"<<endl;
	cout<<"x wins: "<<xwin<<" and o wins: "<<owin<<endl; 
	cout<<"there are "<<cats<<" tie boards"<<endl;
	cout<<"and "<<unfin<<" possible unfinished"<<endl;
	cout<<unfin+xwin+owin+cats<<endl;
	return 0;
}


ostream& operator << (ostream& outs, int board[]) 
{
	for(int i=0;i<size;i++)
	{
		switch(board[i])
		{
			case 0:
				outs<<"_ ";
				break;
			case 1:
				outs<<"x ";
				break;
			case 2:
				outs<<"o ";
				break;
			default:
				outs<<board[i]<<" ";
		}
		if(!((i+1)%3))
			outs<<endl;
	}
	outs<<endl;
 	return(outs);
}

