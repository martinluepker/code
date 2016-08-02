  
using namespace std;

  //works
  template <typename T>   
  ArrayList<T>::ArrayList(int s, const T& x)
  {
    m_size=s;
    m_max=s;                      
    m_data= new T [s];
    for(int i=0;i<m_size;i++)
        m_data[i]=x;
  }
  
  //fine
  template <typename T>
  ArrayList<T>::~ArrayList()
  {
    m_size=0;
    m_max=0;
    delete [] m_data;
    m_data=NULL;
  }
  
  //works
  template <typename T>
  ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rhs)
  {
    if (this == &rhs)
        return *this;
    m_size=rhs.size();
    m_max=rhs.max();
    m_data= new T [m_max];
    for(int n=0;n<m_size;n++)
        m_data[n]=rhs[n];
    return *this;
  }
  
  //fucked
  template <typename T>
  ArrayList<T>::ArrayList(const ArrayList<T>& cpy)
  {
        m_size=cpy.size();
        m_max=cpy.max();
        m_data= new T [m_max];
        for(int n=0;n<m_size;n++)
            m_data[n]=cpy[n];
  }

  //done
  template <typename T>
  int ArrayList<T>::size() const
  {
    return m_size;
  }

  //done
  template <typename T>
  const T& ArrayList<T>::first() const
  {
    if(m_size==0)
    {
        cout<<"!-- ERROR : PANIC in ARRAYLIST.first()!!  (List is empty)"<<endl;
        return m_errobj;
    }
    else
        return m_data[0];
  }
  //done
  template <typename T>
  T& ArrayList<T>::operator[](int i)
  {
    if(i>m_size)
    {
        cout<<"!-- ERROR : PANIC in ARRAYLIST!!.[]  (index out of bounds)"<<endl;
        return m_errobj;
    }
    else
        return m_data[i];
  }
  //done
  template <typename T>
  const T& ArrayList<T>::operator[](int i) const
  {
    if(i>m_size)
    {
        cout<<"!-- ERROR : PANIC in ARRAYLIST!!.[]  (index out of bounds)"<<endl;
        return m_errobj;
    }
    else
        return m_data[i];
  }
  //done
  template <typename T>
  int ArrayList<T>::find(const T& x) const
  {
    for(int i=0;i<m_size;i++)
    {
        if(m_data[i]==x)
            return i;
    }
    return -1;
  }

  //works
  template <typename T>
  void ArrayList<T>::clear()
  {
    m_size=0;
    m_max=0;
    delete [] m_data;
    m_data=NULL;
  }
  
  //working
  template <typename T>                          
  void ArrayList<T>::insert_back(const T& x)
  {
    if(m_size==m_max)
    {
        if(m_max==0)
            m_max++;
        m_max*=2;
        T* temp;
        temp= new T [m_max];
        for(int n=0;n<m_size;n++)
            temp[n]=m_data[n];
        delete [] m_data;
        m_data= new T [m_max];
        for(int n=0;n<m_size;n++)
            m_data[n]=temp[n];
        delete [] temp;
        temp=NULL;
    }
    m_data[m_size]=x;
    m_size++;
  }
  
  //works
  template <typename T>                        
  void ArrayList<T>::insert(const T& x, int i)
  {
    if(i>m_size||i<0)
        cout<<"!-- ERROR : PANIC in ARRAYLIST!!.insert()  (index out of bounds)"<<endl;
    else
    {
        if(m_size==m_max)
        {
            if(m_max==0)
                m_max++;
            m_max*=2;
        }
        T* temp;
        temp= new T [m_max];
        for(int n=0;n<i;n++)
            temp[n]=m_data[n];
        temp[i]=x;
        for(int n=i;n<m_size+1;n++)
            temp[n+1]=m_data[n];
        delete [] m_data;
        m_data= new T [m_max];
        m_size++;
        for(int n=0;n<m_size;n++)
            m_data[n]=temp[n];
        delete [] temp;
        temp=NULL;
    }
  }
  

  template <typename T>
  void ArrayList<T>::remove(int i)
  {
    if(i>m_size||i<0)
        cout<<"!-- ERROR : PANIC in ARRAYLIST!!.remove()  (index out of bounds)"<<endl;
    else
    {
        for(int n=i+1;n<m_size;n++)
            m_data[n-1]=m_data[n];
        m_size--;
        if(m_size<=m_max/4)
        {
            m_max/=2;
            T* temp;
            temp= new T [m_max];
            for(int n=0;n<m_size;n++)
                temp[n]=m_data[n];
            delete [] m_data;
            m_data= new T [m_max];
            for(int n=0;n<m_size;n++)
                    m_data[n]=temp[n];
            delete [] temp;
            temp=NULL;
        }
    }
    
  }

  //?
  template <typename T>
  void ArrayList<T>::swap(int i, int k)
  {
    if(i>m_size||i<0||k>m_size||k<0)
        cout<<"!-- ERROR : PANIC in ARRAYLIST!!.swap()  (index out of bounds)"<<endl;
    else
    {
        T temp=m_data[i];
        m_data[i]=m_data[k];
        m_data[k]=temp;
    }
  }
 
  //
  template <typename T>
  void ArrayList<T>::resize(int s, const T& x)
  {
    if(s<m_size)
    {
        m_size=s;
    }
    else if(s>m_size)
    {
        T* temp;
        temp= new T [m_max]; 
        for(int n=0;n<s;n++)
        {
            if(n<m_size)
                temp[n]=m_data[n];
            else
                temp[n]=x;   
        }
        delete [] m_data;
        m_data= new T [m_max];
        m_size=s;
        for(int n=0;n<m_size;n++)
            m_data[n]=temp[n];
        delete [] temp;
        temp=NULL;
    }
  }
  
  //seems to work
  template <typename T> 
  void ArrayList<T>::append(const ArrayList<T>& alist)
  {
    if(m_max<m_size+alist.size())
    {
        m_max=m_size+alist.size();
        T* temp;
        temp= new T [m_max];
        for(int n=0;n<m_size;n++)
            temp[n]=m_data[n];
        for(int n=0;n<alist.size();n++)
            temp[m_size+n]=alist[n];
        delete [] m_data;
        m_data= new T [m_max];
        m_size=m_size+alist.size();
        for(int n=0;n<m_size;n++)
            m_data[n]=temp[n];
        temp=NULL;
    }
    else
    {
        for(int n=0;n<alist.size();n++)
            m_data[m_size+n]=alist[n];
        m_size=m_size+alist.size();
    }
  }
  
