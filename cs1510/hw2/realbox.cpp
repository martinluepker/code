/*
Martin Luepker
section C
*/

#include "realbox.h"
using namespace std;

RealBox::RealBox(int s, float a)
{
    m_boxsize=s;
    m_reals= new float [s];
    for(int i=0;i<m_boxsize;i++)
        m_reals[i]=a;
}

RealBox::~RealBox()
{
    delete[] m_reals;
}

const RealBox&  RealBox::operator=(const RealBox& rhs)
{
    if (this == &rhs)
        return *this;
        
    m_boxsize=rhs.m_boxsize;
    
    delete[] m_reals;
    m_reals= new float [m_boxsize];
    for(int i=0;i<m_boxsize;i++)
        m_reals[i]=rhs.m_reals[i];
    return *this;
}

RealBox::RealBox(const RealBox& rhs)
{
    m_boxsize=rhs.m_boxsize;
    
    delete[] m_reals;
    
    m_reals= new float [m_boxsize];
    
    for(int i=0;i<m_boxsize;i++)
        m_reals[i]=rhs.m_reals[i];
}

void RealBox::set( int i, float x)
{
    m_reals[i]=x;
}

ostream& operator<< (ostream& out,const RealBox& box)
{
    out<<"[";
    for(int i=0;i<box.m_boxsize;i++)
        out<<box.m_reals[i]<<", ";
    cout<<"]"<<endl;
    return(out);
}
                                   