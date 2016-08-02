    
#ifndef QUEUE_H
#define QUEUE_H
#include "abstractqueue.h"

template <typename T>
class Node
{
public:
	T data;
	Node *next;
    Node(const T info, Node *nextValue = NULL)
	{
		data = info;
		next = nextValue;
	}
};

// Queue class.
template <typename T>
class Queue:public AbstractQueue<T>
{
private:
	Node<T> *frontptr;
	Node<T> *backptr;
	int size;

public:
	
    Queue():frontptr(NULL), backptr(NULL), size(0) {}
	virtual bool isEmpty() const;
	virtual void clear();
	virtual void enqueue(const T& x);
	virtual void dequeue();
    virtual const T& back() const throw (Oops);
    virtual const T& front() const throw (Oops);
    ~Queue();

};

#include "queue.hpp"

#endif

