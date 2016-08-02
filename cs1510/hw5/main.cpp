#include <iostream>
#include <iomanip>
#include "benderrobot.h"
#include "welderrobot.h"
#include "wrapperrobot.h"
using namespace std;

int main()
{
    int robotnum;
    float totalpay;
   
    cout.setf(ios_base::fixed,ios_base::floatfield); 
    cout.precision(2);

    cin>>robotnum;
    for(int i=0;i<robotnum;i++)
    {
        int type;
        string name;
        cin>>type;
        cin>>name;
        switch(type)
        {
            //wrapper
            case 0:
                {
                int hours;
                int packs;
                cin>>hours;
                cin>>packs;
                AbstractRobot *robot0= new WrapperRobot(name,hours,packs);
                cout<<"#"<<i<<": "<<robot0->getName()<<", "<<robot0->getType()<<" $"<<robot0->getPay()<<endl;
                totalpay+=robot0->getPay();
                delete robot0;
                }
                break;
            //bender
            case 1:
                {
                int hours;
                int extra;
                int bends;
                cin>>hours;
                cin>>extra;
                cin>>bends;
                AbstractRobot *robot1= new BenderRobot(name,hours,extra,bends);
                cout<<"#"<<i<<": "<<robot1->getName()<<", "<<robot1->getType()<<" $"<<robot1->getPay()<<endl;
                totalpay+=robot1->getPay();
                delete robot1;
                }
                break;
            //welder
            case 2:
                {
                int hours;
                int extra;
                int radio;
                cin>>hours;
                cin>>extra;
                cin>>radio;
                AbstractRobot *robot2= new WelderRobot(name,hours,extra,radio);
                cout<<"#"<<i<<": "<<robot2->getName()<<", "<<robot2->getType()<<" $"<<robot2->getPay()<<endl;
                totalpay+=robot2->getPay();
                delete robot2;
                }
                break;
        }
    }
    cout<<"TOTAL PAY = "<<totalpay<<endl<<"AVERAGE PAY = "<<totalpay/static_cast<float>(robotnum)<<endl;
    return 0;
}