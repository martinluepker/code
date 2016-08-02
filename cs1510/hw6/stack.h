
#ifndef STACK_H
#define STACK_H
#include "abstractstack.h"


template <typename T>
struct Node
{
    T data;            
    Node<T>* next;   
};

template <typename T>
class Stack: public AbstractStack<T>
{
    private:
        Node<T>* head;
        int size;
        T error;
    public:
        Stack() : head(NULL), size(0), error(0) {}
        virtual bool isEmpty() const {return !size;}
        virtual const T& top() const;
        virtual void push(const T& x);
        virtual void pop();
        virtual void clear();
        void print() const;
        const int getSize() const {return size;}
        ~Stack();
};

#include "stack.hpp"

#endif