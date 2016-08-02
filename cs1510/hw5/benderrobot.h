#ifndef BENDER_H
#define BENDER_H
#include "abstractrobot.h"
using namespace std; 

class BenderRobot :public  AbstractRobot
{
    private:
    float pay;
    float extrapay;
    float perbend;
    int hours;
    int extra;
    int bends;
    string type;
    public:
    BenderRobot(string n,int t, int e, int b);
    virtual float getPay() const;
    virtual const string& getName () const;
    virtual const string& getType() const;
    ~BenderRobot() {}
};


#endif