#ifndef GRAPH_H
#define GRAPH_H
#include "linkedlist.h"
using namespace std;
class Graph
{
    private:
        string name;
        List *nodes;
        string *names;
        int *costs;
        int size;
        int max;
        int money;
        int edgenum;
        bool recursivecosts(int pos,bool*visited);
    public:
        Graph(string n, int s,int m); 
        int find(string n);
        bool isfull() {return size==max;}
        void addnode(string name);
        void addedge(int w,int pos,string n);
        void findcosts();
        void results();
};

#endif