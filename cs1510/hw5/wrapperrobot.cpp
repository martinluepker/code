#include "wrapperrobot.h"

WrapperRobot::WrapperRobot(string n,int t,int p):AbstractRobot(n)
{
    hours=t;
    packs=p;
    pay=0.25;
    perpack=0.05;
    type="WrapperRobot";
}
float WrapperRobot::getPay() const
{
    return pay*hours+packs*perpack;
}
const string& WrapperRobot::getName() const
{
    return m_name;  
}

const string& WrapperRobot::getType() const
{
    return type;
}