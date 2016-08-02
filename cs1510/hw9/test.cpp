#include <iostream>
#include "mybstree.h"
using namespace std;

int main()
{
    MyBSTree<int> t;
    try 
    {
        t.findMin();
    }
    catch (Oops err)
    {
        cout << err.getMsg() << endl;
    }
  
    cout << endl << endl << "***** " << "Test #1" << endl;
    
    t.print();
    cout << "Tree empty? " << boolalpha << t.isEmpty() << endl;
        
    cout << "--" << endl;

    t.insert(7);
    t.insert(5);
    t.insert(9);
    t.insert(4);
    t.insert(6);
    t.insert(13);
    cout << "size = " << t.size() << endl;
    t.insert(10);
    cout << "size = " << t.size() << endl;
    t.remove(10);
   // t.print();
    cout << "Tree empty? " << boolalpha << t.isEmpty() << endl;
    cout << "--" << endl;
    //cout << "height = " << t.height() << endl;
    cout << "size = " << t.size() << endl;
    cout << "--" << endl;
    cout<<"penis"<<endl;
    return 0;
}