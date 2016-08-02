#include "benderrobot.h"

BenderRobot::BenderRobot(string n,int t, int e, int b):AbstractRobot(n)
{   
    hours=t;
    extra=e;
    bends=b;
    pay=0.45;
    extrapay=0.65;
    perbend=0.02;
    type="BenderRobot";
}

float BenderRobot::getPay() const
{
    return hours*pay+extra*extrapay+bends*perbend;
}
const string& BenderRobot::getName() const
{
    return m_name; 
}

const string& BenderRobot::getType() const
{
    return type;
}