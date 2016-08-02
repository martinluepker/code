
#include "linkedlist.h"

List::List()
{
    head=NULL;
    size=0;
}


List::~List()
{
    clear();
}

void List::clear()
{
    Node* current=head;
    while (current != NULL) 
    {
        head = head->next;
        delete current;
        current = head;
        size--;
    }
}


Node* List::getptr(int n)
{
    Node *current=head;
    for(int i=0;i<n;i++)
        current=current->next;
    return current;
}


void List::print()
{
    Node *current=head;
    if(current!=NULL)
    {
        while(current->next != NULL) 
        {
            cout<<current->name<<" "<<current->weight<<" ";
            current=current->next;
        }
        cout<<current->name<<" "<<current->weight<<" "<<endl;
    }
}

void List::insert(const int w,const string n)
{
    if(head==NULL)
    {
        head=new Node;
        head->weight=w;
        head->name=n;
        head->next=NULL;
    }
    else
    {
    Node* current=head;
    while (current->next != NULL) 
        current=current->next;
    current->next=new Node;
    current=current->next;
    current->weight=w;
    current->name=n;
    current->next=NULL;
    }
    size++;
}

