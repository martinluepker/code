#ifndef NET_H
#define NET_H

#include <iostream>

template <typename T>
class Node
{
    T data;
    
    Node();
    
};


template <typename T>
class Net
{
    int size;
    Node* first;
};

#include"net.hpp";
#endif