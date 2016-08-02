//Martin Luepker
//Lecture C

#ifndef BSTREE_H
#define BSTREE_H
#include "abstractbstree.h"
template <typename T> 
struct Node
{
    T data; 
    Node* right; 
    Node* left;
};


template <typename T> 
class MyBSTree : public AbstractBSTree<T>
{
    private:
        int num;
        Node<T>* root;
        void recursive_insert(Node<T>* newNode, Node<T> *&cur);
        int recursive_find(const T& x,Node<T>* cur, int d) const;
        int recursive_height(Node<T>* cur) const;
        void recursive_remove(Node<T> *delNode, Node<T> *&cur);
        Node<T>* getPointer(const T& x,Node<T> *&cur);
        Node<T>* findSubMin(Node<T> *cur);
        void prettyPrint (const Node<T>* t, int pad) const;
    public:
        void operator=(const MyBSTree &a);
        MyBSTree():num(0),root(NULL){}
        virtual int size() const {return num;}
        virtual bool isEmpty() const {return root==NULL;}
        virtual int height() const;
        virtual const T& findMax() const throw (Oops);
        virtual const T& findMin() const throw (Oops);
        virtual int find(const T& x) const;
        virtual void clear();
        virtual void insert(const T& x);
        virtual void remove(const T& x);
        virtual void printPreOrder() const;
        virtual void printPostOrder() const;
        virtual void print() const; 
        ~MyBSTree();
};

#include "mybstree.hpp"

#endif