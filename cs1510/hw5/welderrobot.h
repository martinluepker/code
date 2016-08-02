#ifndef WELDERROBOT_H
#define WELDERROBOT_H
#include "abstractrobot.h"
using namespace std; 

class WelderRobot:public AbstractRobot
{
    private:
    float pay;
    float extrapay;
    float radiopay;
    float bonus;
    int hours;
    int extra;
    int radio;
    string type;
    public:
    WelderRobot(string n,int t,int e,int r);
    virtual float getPay() const;
    virtual const string& getName() const;
    virtual const string& getType() const;
    ~WelderRobot(){}
};

#endif