#include "welderrobot.h"

WelderRobot::WelderRobot(string n,int t,int e,int r): AbstractRobot(n)
{
    hours=t;
    extra=e;
    radio=r;
    pay=0.55;
    extrapay=0.75;
    radiopay=1;
    bonus=9.99;
    type="WelderRobot";
}

float WelderRobot::getPay() const
{
    return hours*pay+extra*extrapay+radio*radiopay+bonus;
}
const string& WelderRobot::getName() const
{
    return m_name; 
}

const string& WelderRobot::getType() const
{
    return type;
}