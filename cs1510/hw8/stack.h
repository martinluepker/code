#ifndef STACK_H
#define STACK_H


template <typename T>
struct Node
{
    T data;            
    Node<T>* next;   
};

template <typename T>
class Stack
{
    private:
        Node<T>* head;
        int size;
        T error;
    public:
        Stack() : head(NULL), size(0), error(0) {}
        bool isEmpty() const {return !size;}
        const T& top() const;
        void push(const T& x);
        void pop();
        void clear();
        void print() const;
        const int getSize() const {return size;}
        T operator[](int i);
        ~Stack();
};

#include "stack.hpp"

#endif