//Martin Luepker

#include <iostream>
using namespace std;

template <typename T>   
LinkedList<T>::~LinkedList()
{
    clear();
}

//I cant get this to work
template <typename T> 
const LinkedList<T>&  LinkedList<T>::operator= (const LinkedList<T>& rhs) 
{
    if(this != &rhs)
    {
        clear();
        Node<T> *current=rhs.m_head;
        
        while(current!=NULL)
        {
           insert(current->m_data,current);
           current=current->m_next;
        }
    }
    return *this;
}
//I cant get this to work
template <typename T>  
LinkedList<T>::LinkedList(const LinkedList<T>& rhs) 
{
    if(this != &rhs)
    {
        clear();
        Node<T> *current=rhs.m_head;
        
        while(current!=NULL)
        {
           insert(current->m_data,current);
           current=current->m_next;
        }
    }
}

//done
template <typename T>
int LinkedList<T>::size() const
{
    return m_size;  
}


template <typename T>
bool LinkedList<T>::isEmpty() const
{
    return m_head==NULL?1:0;
}


template <typename T>  
Node<T>* LinkedList<T>::getFirstPtr() const
{
    if(m_size==0)
    {
        cout<<"!!-- ERROR : PANIC in LINKEDLIST.getFirstPtr() - empty index"<<endl;
        return NULL;
    }
    return m_head;
}


template <typename T> 
Node<T>* LinkedList<T>::getLastPtr()
{
    if(m_size==0)
    {
        cout<<"!!-- ERROR : PANIC in LINKEDLIST.getLastPtr() - empty index"<<endl;
        return NULL;
    }
    Node<T>* last=m_head;
    while(last->m_next!=NULL)
        last=last->m_next;
    return last;
}


template <typename T> 
Node<T>* LinkedList<T>::getAtPtr(int i)
{
    if(i>m_size||i<0)
    {
        cout<<"!!-- ERROR : PANIC in LINKEDLIST.getAtPtr() - invalid index"<<endl;
        return NULL;
    }
    Node<T>* current=m_head;
    for(int n=0;n<i;n++)
        current=current->m_next;
    return current;
}


template <typename T> 
void LinkedList<T>::clear()
{
    
    Node<T> *current=m_head;
     while (current != NULL) 
     {
        m_head = m_head->m_next;
        delete current;
        current = m_head;
        m_size--;
    }
}

template <typename T> 
void LinkedList<T>::insert_front(const T& x)
{
    m_head= new Node<T>(x,m_head);
    m_size++;
}

template <typename T> 
void LinkedList<T>::insert(const T& x, Node<T>* pos)
{
    Node<T>* prev=m_head;
    while(prev->m_next!=pos)
        prev=prev->m_next; 
    prev->m_next= new Node<T>(x,prev->m_next);
    m_size++;
}


template <typename T> 
void LinkedList<T>::remove(Node<T>* pos)
{   
    Node<T>* prev=m_head;
    while(prev->m_next!=pos)
        prev=prev->m_next; 
    prev->m_next=prev->m_next->m_next;
    delete pos;
    m_size--;
}

template <typename T> 
bool LinkedList<T>::operator== (const LinkedList<T>& rhs) const
{
    Node<T>* cur1=m_head;
    Node<T>* cur2=rhs.m_head;
    if(m_size!=rhs.size())
        return 0;
    for(int n=0;n<m_size;n++)
    {
        if(cur1->m_data!=cur2->m_data)
            return 0;
        cur1=cur1->m_next;
        cur2=cur2->m_next;
    }
    return 1;  
}

template <typename T> 
Node<T>* LinkedList<T>::find(const T& x)
{
    Node<T>* current=m_head;
    for(int n=0;n<m_size;n++)
    {
        if(current->m_data==x)
            return current;
        current=current->m_next;
    }
    return NULL;
}


template <typename T> 
void LinkedList<T>::append(const LinkedList<T>& xlist)
{
    getLastPtr()->m_next=xlist.m_head;
}
