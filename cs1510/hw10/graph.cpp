#include <cstring>
#include "graph.h"

Graph::Graph(string n, int s,int m)
{
    name=n;
    money=m;
    size=0;
    max=s;
    nodes= new List [s];
    names= new string [s]; 
    costs= new int [s];
    for(int i=0;i<s;i++)
    {
        costs[i]=money*money;
    }
    edgenum=0;
}

int Graph::find(string n)
{
    int pos=-1;
    for(int i=0;i<size;i++)
    {
        if(n==names[i])
            pos=i;
    }  
    return pos;
}

void Graph::addnode(string name)
{
    if(size!=max)
    {
        names[size]=name;
        size++;
    }
}

void Graph::addedge(int w, int pos,string n)
{
    nodes[pos].insert(w,n);
    edgenum++;
}


void Graph::findcosts()
{ 
    bool visited[size];
    costs[0]=0;
    for(int i=0;i<size;i++)
        visited[i]=0;
    recursivecosts(0,visited);
    for(int i=0;i<size;i++)
        visited[i]=0;
    //check
    recursivecosts(0,visited);
}

bool Graph::recursivecosts(int pos,bool *visited)
{
    
    bool visitedall=1;
    for(int i=0;i<size;i++)
    {
        if(!visited[i])
            visitedall=0;
    }
    if(visitedall)
        return 1;
    
    visited[pos]=1;    
        
    int prev=pos;
    for(int i=0;i<nodes[prev].getsize();i++)
    {
        Node* cur=nodes[prev].getptr(i);
        pos=find(cur->name);
        int price=cur->weight+costs[prev];
        costs[pos]>price?costs[pos]=price:costs[pos]=costs[pos];
        recursivecosts(pos,visited);
    } 
    return 1;
    
}

void Graph::results()
{       
       cout<<endl<<"In "<<name<<", Dr. Zoidberg can reach:";
       bool some=0;
       for(int i=1;i<size;i++)
       {
           if(costs[i]<=money)
           {
               some=1;
               cout<<endl<<names[i]<<" ";
           }
       } 
       if(!some)
            cout<<"nothing";
    cout<<endl;
}