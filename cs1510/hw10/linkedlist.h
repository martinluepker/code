#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;

class Node
{
  public:
    int weight;
    Node* next;
    string name;
};  

class List
{
  private:
    Node* head;
    int size;
  public:
    List();
    ~List();
    void clear();
    int getsize() const {return size;}
    Node* getptr(int i);
    void insert(const int w,const string n);
    void print();
};


#endif
