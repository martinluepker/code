    
    template <typename T> 
    void MyBSTree<T>::recursive_insert(Node<T>* newNode, Node<T> *&cur)
    {

        if (cur == NULL) 
            cur = newNode;
        else if (newNode->data < cur->data)
            return recursive_insert (newNode,cur->left);
        else if (newNode->data > cur->data)
            return recursive_insert(newNode, cur->right); 
    }
    
    template <typename T> 
    void MyBSTree<T>::insert(const T& x)
    {
        Node<T>* newNode;
        newNode->data=x;
        newNode->right=NULL;
        newNode->left=NULL;
        recursive_insert(newNode,root);
        num++;
    }

    template <typename T> 
    int MyBSTree<T>::recursive_find(const T& x,Node<T>* cur, int d) const
    {
        return 1;
    }
    
     template <typename T>
     void MyBSTree<T>::operator=(const MyBSTree &a)
     {
         
     }
     

     
     
    
    template <typename T> 
    int MyBSTree<T>::find(const T& x) const
    {
        return recursive_find(x,root,1);
    }    
 
    template <typename T> 
    const T& MyBSTree<T>::findMin() const throw (Oops)
    {
        Oops err("OOPS! : Tree is Empty!!");
        if(!num)
            throw err;

        Node<T>*cur=root;
        while(cur->left!=NULL)
            cur=cur->left;
        return cur->data;
    }
    
    template <typename T> 
    const T& MyBSTree<T>::findMax() const throw (Oops)
    {
        Oops err("OOPS! : Tree is Empty!!");
        if(!num)
            throw err;
      
        Node<T>*cur=root;
        while(cur->right!=NULL)
            cur=cur->right;
        return cur->data;
    }
    
    template <typename T> 
    int MyBSTree<T>::recursive_height(Node<T>* cur) const
    {
        if (cur==NULL) { 
            return(0); 
        } 
        else 
        { 
            int l = recursive_height(cur->left); 
            int r = recursive_height(cur->right);
            if (l > r) 
                return(l+1); 
            else 
                return(r+1); 
        } 
    }
    
    
    template <typename T> 
    int MyBSTree<T>::height() const
    {
        return recursive_height(root);    
    }
    
    template <typename T>  
    Node<T>* MyBSTree<T>::getPointer(const T& x,Node<T> *&cur)
    {
        if (cur == NULL) 
            return NULL;
        else if (x < cur->data)
            return getPointer(x,cur->left);
        else if (x > cur->data)
            return getPointer(x, cur->right);
        else
            return cur; 
    }
    
    template <typename T>  
    Node<T>* MyBSTree<T>::findSubMin(Node<T> *cur)
    {
        while(cur->left!=NULL)
            cur=cur->left;
        return cur;
    }
    
    
    template <typename T>  
    void MyBSTree<T>::remove(const T& x)
    {
        Node<T> *temp=getPointer(x,root);
        if(temp!=NULL)
            recursive_remove(temp,root);
        num--;
    }
    
    template <typename T> 
    void MyBSTree<T>::recursive_remove(Node<T> *delNode, Node<T> *&cur)
    {
        if (root == NULL) 
            return;
        else if(delNode->data < cur->data)
            recursive_remove(delNode,cur->left);
        else if(delNode->data > cur->data)
            recursive_remove(delNode, cur->right); 
        else if (!delNode->left && !delNode->right)
        {
            Node<T> *temp;
            temp = findSubMin(cur->right);
            delNode->data = temp->data;
            recursive_remove(temp, cur->right);
        }
        else if (!delNode->left)
            delNode= delNode->left;
        else if (!delNode->right)
            delNode= delNode->right;
        else
            delNode = NULL; 
    }    
    
    template <typename T> 
    void MyBSTree<T>::clear()
    {
        while(num!=0)
            remove(root->data);
    }
    
    template <typename T> 
    void MyBSTree<T>::printPreOrder() const
    {
        
    }
    
    template <typename T> 
    void MyBSTree<T>::printPostOrder() const
    {
        
    }
    
    template <typename T> 
    void MyBSTree<T>::print() const
    {
        prettyPrint(root,0);
    }
    
    template <typename T>  
    MyBSTree<T>::~MyBSTree()
    {
        clear();
    }
    
    
    
    template <typename T>
    void MyBSTree<T>::prettyPrint (const Node<T>* t, int pad) const
    {
        string s(pad, ' '); 
        if (t == NULL)
            cout << endl; 
        else
        {
            prettyPrint(t->right, pad+4); 
            cout << s << t->data << endl; 
            prettyPrint(t->left, pad+4);
        }
    }