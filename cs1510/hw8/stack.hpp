
    #include <iostream>
    using namespace std;
    
    template <typename T>
    const T& Stack<T>::top() const
    {
        if(head==NULL)
            return error;
        else
            return head->data;
    }
    
    template <typename T>
    void Stack<T>::push(const T& x)
    {
        Node<T>* pos=head;
        head= new Node<T>;
        head->next=pos;
        head->data=x;
        size++;
    }
    
    template <typename T>
    void Stack<T>::pop()
    {
        if(head!=NULL)
        {
            Node<T>* pos=head;
            head=head->next;
            delete pos;
            size--;
        }
    }
    
    template <typename T>
    void Stack<T>::clear()
    {
        Node<T> *current=head;
        while (current != NULL) 
        {
            head = head->next;
            delete current;
            current = head;
            size--;
        }
    }
    
    template <typename T>
    void Stack<T>::print() const
    {
        cout<<"[ ";
        Node<T> *current=head;
        while (current != NULL) 
        {
            cout<<current->data<<" ";
            current=current->next;
            
        }
        cout<<"]"<<endl;
    }
    
    template <typename T>
    T Stack<T>::operator[](int n)
    {
        if(n>size)
        {
            return error;
        }
        else
        {
            T temp;
            Node<T> *current=head;
            for(int i=0;i<=n;i++)
            {
                temp=current->data;
                current=current->next;
            }
            return temp;
        }
    }
    
    template <typename T>
    Stack<T>::~Stack()
    {
        clear();
    }