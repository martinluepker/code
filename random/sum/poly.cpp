#include<iostream>
#include<math.h>
using namespace std;

const char *super[] = {"\xe2\x81\xb0", "\xc2\xb9", "\xc2\xb2",
    "\xc2\xb3", "\xe2\x81\xb4", "\xe2\x81\xb5", "\xe2\x81\xb6",
    "\xe2\x81\xb7", "\xe2\x81\xb8", "\xe2\x81\xb9"};


class term
{
    private:
        int numer;
        int denom;
        int degree;
    public:
    term(int num,int den,int deg);
    term():numer(0),denom(1),degree(0){}
    int getnum() const {return numer;} 
    int getden() const {return denom;} 
    int getdeg() const {return degree;} 
    void setnum(int num){numer=num;}
    void setden(int den);
    void setdeg(int deg){degree=deg;}
    void operator=(const term &a);
    void simplify();
    friend term operator+(term &a,term &b);
    friend term operator-(term &a,term &b);
    friend term operator*(term &a,term &b);
    friend term operator/(term &a,term &b);
    friend ostream& operator<<(ostream& out, const term& a);
};

term::term(int num,int den,int deg)
{
    numer=num;
    if(den)
        denom=den;
    else
    {
        cout<<"div 0s"<<endl;
        denom=1;
    }

    degree=deg;
    simplify();
}

void term::setden(int den)
{
    if(den)
        denom=den;
    else
        cout<<"div 0s"<<endl;
}

void term::operator=(const term& a)
{
    numer=a.numer;
    denom=a.denom;
    degree=a.degree;
}

void term::simplify()
{
    int a=numer;
    int b=denom;
    int t;
    while(b)
    {
        t=b;
        b=a%b;
        a=t;
    }
    if(a)
    {
        numer/=a;
        denom/=a;
    }
}

term operator+(term &a,term &b)
{
    term temp;
    if(a.degree==b.degree)
    {
        temp.numer=a.numer*b.denom+a.denom*b.numer;
        temp.denom=a.denom*b.denom;
        temp.degree=a.degree;
    }
    else
    {
        cout<<"cant add terms of different degrees"<<endl;
    }
    temp.simplify();
    return temp;
}

term operator-(term &a,term &b)
{
    term temp;
    if(a.degree==b.degree)
    {
        temp.numer=a.numer*b.denom-a.denom*b.numer;
        temp.denom=a.denom*b.denom;
        temp.degree=a.degree;
    }
    else
    {
        cout<<"cant subtract terms of different degrees"<<endl;
    }
    temp.simplify();
    return temp;
}

term operator*(term &a,term &b)
{
    term temp(a.numer*b.numer,a.denom*b.denom,a.degree+b.degree);
    temp.simplify();
    return temp;
}
term operator/(term &a,term &b)
{
    term temp(a.numer*b.denom,a.denom*b.numer,a.degree-b.degree);
    temp.simplify();
    return temp;
}

void superscript(int n)
{
    if(n<0)
    {
        cout<<"\u207B";
        n*=-1;
    }
    if(n)
    {
        for(int i=0;i<floor(log10(n))+1;i++)
            cout<<super[static_cast<int>(floor(n/pow(10,floor(log10(n)-i))))%10];
    }
    else
        cout<<super[0];
}

ostream& operator<<(ostream& out, const term& a)
{
    if(a.denom==0)
        out<<"div 0p"<<endl;
    else if(a.numer==0)
        cout<<" ";
    else
    {
        if(a.denom!=1)
        {
            
            if(!a.degree)
                out<<a.numer<<"/"<<a.denom;
            else if(a.degree==1)
                out<<a.numer<<"/"<<a.denom<<"x";
            else
            {
                out<<a.numer<<"/"<<a.denom<<"x";
                superscript(a.degree);
            }
        }
        else
        {
            if(a.numer==1)
            {
                if(!a.degree)
                    out<<a.numer;
                else if(a.degree==1)
                    out<<"x";
                else
                {
                    out<<"x";
                    superscript(a.degree);
                }
            }
            else
            {
                if(!a.degree)
                    out<<a.numer;
                else if(a.degree==1)
                    out<<a.numer<<"x";
                else
                {
                    out<<a.numer<<"x";
                    superscript(a.degree);
                }
            }
        }
    }
    return out;
}


class polynomial 
{
    private:
        term* values;
        int degree;
    public:
        polynomial(int d);
        polynomial();
        ~polynomial();
        void clear();
        int getdegree() const {return degree;} 
        void operator=(const polynomial &a);
        void operator=(const term &a);
        term& operator [](int i);
        const term& operator[](int i) const;
        friend polynomial operator+(polynomial &a,polynomial &b);
        friend polynomial operator-(polynomial &a,polynomial &b);
        friend polynomial operator*(polynomial &a,polynomial &b); 

        friend polynomial operator+(polynomial &a,term &b);
        friend polynomial operator-(polynomial &a,term &b);
        friend polynomial operator*(polynomial &a,term &b); 

        friend polynomial operator+(term &a,polynomial &b);
        friend polynomial operator-(term &a,polynomial &b);
        friend polynomial operator*(term &a,polynomial &b);   
        friend ostream& operator<<(ostream& out, const polynomial& a);

        
        polynomial binomial(int d);
};


polynomial::polynomial(int d)
{
    degree=d;
    values=new term[d+1];
    for(int i=0;i<d+1;i++)
    {
        values[i].setnum(0);
        values[i].setden(1);
        values[i].setdeg(i);
    }
}

polynomial::polynomial()
{
    degree=0;
    values=new term[degree+1];
    values[0].setnum(0);
    values[0].setden(1);
    values[0].setdeg(0);

}
polynomial::~polynomial()
{
    clear();
}

void polynomial::clear()
{
    degree=0;
    delete [] values;
    values=NULL;
}

term& polynomial::operator [](int i)
{
    if(i<=degree)
        return values[i];
    else
        return values[0];
}

const term& polynomial::operator[](int i) const
{
    if(i<=degree)
        return values[i];
    else
        return values[0];
}

void polynomial::operator=(const polynomial &a)
{
    clear();
    degree=a.getdegree();
    values= new term[degree+1];
    for(int i=0;i<=degree;i++)
        values[i]=a[i];
}


void polynomial::operator=(const term &a)
{
    clear();
    degree=a.getdeg();
    values= new term[degree+1];
    values[degree]=a;
    term temp;
    for(int i=0;i<degree;i++)
        values[i]=temp;
}


polynomial operator+(polynomial &a,polynomial &b)
{
    if(a.getdegree()>b.getdegree())
    {
        polynomial temp(a.getdegree());
        for(int i=0;i<=b.getdegree();i++)
             temp[i]=a[i]+b[i];
        for(int i=b.getdegree()+1;i<=a.getdegree();i++)
            temp[i]=a[i];
        return temp;
    }
    else
    {
        polynomial temp(b.getdegree());
        for(int i=0;i<=a.getdegree();i++)
             temp[i]=a[i]+b[i];
        for(int i=a.getdegree()+1;i<=b.getdegree();i++)
            temp[i]=b[i];
        return temp;
    }
    
    
}

polynomial operator-(polynomial &a,polynomial &b)
{
    term neg(-1,1,0);
    for(int i=0;i<b.degree;i++)
    {
        b[i]=neg*b[i];
    }
    return (a+b);

}

ostream& operator<<(ostream& out, const polynomial& a)
{
    for(int i=a.degree;i>=0;i--)
    {
        if(a[i].getnum())
            cout<<a[i];
        bool smaller=0;
        for(int j=0;j<i;j++)
            a[j].getnum()?smaller=1:NULL;
        if(a[i].getnum()&smaller)
            out<<"+";
    }
    return out;
}


polynomial operator*(polynomial &a,polynomial &b)
{
    polynomial temp(a.getdegree()+b.getdegree());
    for(int i=0;i<=a.getdegree();i++)
    {
        for(int t=0;t<=b.getdegree();t++)
        {
            term ab=a[i]*b[t];
            temp[i+t]=ab+temp[i+t];
        }
    }
    return temp;
}


polynomial operator+(polynomial &a,term &b)
{
    polynomial temp;
    temp=b;
    return(a+temp);
}
polynomial operator-(polynomial &a,term &b)
{
    polynomial temp;
    temp=b;
    return(a-temp);
}
//polynomial operator*(polynomial &a,term &b);

polynomial operator+(term &a,polynomial &b)
{
    polynomial temp;
    temp=a;
    return(temp+b);
}
polynomial operator-(term &a,polynomial &b)
{
    polynomial temp;
    temp=a;
    return(temp-b);
}
//polynomial operator*(term &a,polynomial &b); 

int main()
{
    
    term a(19,18,0);
    term b(11,10,1);
    term c(5,4,2);
    polynomial abc(2);
    abc[0]=a;
    abc[1]=b;
    abc[2]=c;
    cout<<a<<" / "<<b<<"="<<a/b<<endl;
    cout<<abc[2]<<"+"<<abc[1]<<"+"<<abc[0]<<endl;
    abc=(abc+abc);
    cout<<abc<<endl;
    cout<<abc<<endl;
    term d;
    abc[2]=d;
    cout<<abc<<endl;
    polynomial efg;
    cout<<efg<<endl;
    efg=abc;
    cout<<efg<<endl;
    polynomial pb;
    pb=b;
    cout<<pb<<endl;
    pb=pb+a;
    cout<<pb<<endl;
    //pb=pb*a;
    return 0;
}