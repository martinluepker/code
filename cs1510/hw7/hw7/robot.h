#ifndef ROBOT_H
#define ROBOT_H
#include "queue.h"
class Robot
{
    private:
        string name; 
        //w is memwipe
        //m is metalwork
        //o is oilbath
        //p is paint 
        Queue<string> * services;
    public:
        void add(string a)
        {
            services->enqueue(a);
        }
        const string & getService()
        {
            return services->front();
        }
        string & getname()
        {
            return name;
        }
};



#endif
