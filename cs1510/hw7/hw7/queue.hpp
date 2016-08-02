
#include <iostream> 
using namespace std;


template <typename T>
Queue<T>::~Queue()
{
	clear();
}

template <typename T>
bool Queue<T>::isEmpty() const
{
	
	return frontptr == NULL;
}

template <typename T>
void Queue<T>::clear()
{
	Node<T> *temp;
	while (frontptr != NULL)
	{
		temp = frontptr->next;
		delete frontptr;
		frontptr = temp;
	}
}

template <typename T>
void Queue<T>::enqueue(const T& x)
{
	Node<T> *node = new Node<T>(x);
	size++;
	if (isEmpty())
	{
		frontptr = backptr= node;
	}
	backptr->next = node;
	backptr = node;
    backptr->data=x;
}

template <typename T>
void Queue<T>::dequeue()
{
	Node<T> *temp = frontptr;
	frontptr = frontptr->next;
	delete temp;
	size--;
}

template <typename T>
const T& Queue<T>::back() const throw (Oops)
{
    return backptr->data;
}

template <typename T>
const T& Queue<T>::front() const throw (Oops)
{
    return frontptr->data;
}