#ifndef WRAPPERROBOT_H
#define WRAPPERROBOT_H
#include "abstractrobot.h"

class WrapperRobot :public AbstractRobot
{
    private:
    float pay;
    float perpack;
    int hours;
    int packs;
    string type;
    public:
    WrapperRobot(string n,int t,int p);
    virtual float getPay() const;
    virtual const string& getName() const;
    virtual const string& getType() const;
    ~WrapperRobot(){}
};

#endif