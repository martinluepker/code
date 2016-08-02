//Martin Luepker
#include "stack.h"
#include <cstdlib>
#include <string>
int main()
{
    
    string input;
    Stack<int> stack;
    bool on=1;
    
    do
    {
        cin>>input;
        //all numbers
        //all the operators are 1 long so none of them will be include with the first part
        //and the second part includes only 0 through 9
        if(input.length()!=1||(input.c_str()[0]>='0'&&input.c_str()[0]<='9'))
        {
            stack.push(atoi(input.c_str()));
        }
        //all operators 
        else 
        {
            
            int value;//saves values for the operators
            switch(input.c_str()[0])
            {
                case '+':
                    if(stack.getSize()>=2)
                    {    
                        value=stack.top();
                        stack.pop();
                        value+=stack.top();
                        stack.pop();
                        stack.push(value);
                    }  
                    else 
                        cout<<"Not enough operands!"<<endl;
                    break;
                    
                case '-':
                    if(stack.getSize()>=2)
                    {     
                        value=stack.top();
                        stack.pop();
                        value=stack.top()-value;
                        stack.pop();
                        stack.push(value);
                    }  
                    else 
                        cout<<"Not enough operands!"<<endl;
                    break;
                    
                case '/':
                    if(stack.getSize()>=2)
                    {  
                        value=stack.top();
                        if(value==0)
                        {
                            stack.pop();
                            value=stack.top()/value;
                            stack.pop();
                            stack.push(value);
                        }
                        cout<<"Cannot Divide by 0"<<endl;
                    }  
                    else 
                        cout<<"Not enough operands!"<<endl;
                    break;
                    
                case '*':
                    if(stack.getSize()>=2)
                    {    
                        value=stack.top();
                        stack.pop();
                        value*=stack.top();
                        stack.pop();
                        stack.push(value);
                    }  
                    else 
                        cout<<"Not enough operands!"<<endl;
                    break;
                    
                case '!':
                    stack.print();     
                    break;
                    
                case 'S':
                        if(!stack.isEmpty())
                        {
                            value=0;
                            while(!stack.isEmpty())
                            { 
                                value+=stack.top();
                                stack.pop();
                            }
                            stack.push(value);
                        }
                        else
                            cout<<"Stack is Empty!"<<endl;
                    break;
                    
                case 'P':
                    if(!stack.isEmpty())
                    {
                        value=1;
                        while(!stack.isEmpty())
                        { 
                            value*=stack.top();
                            stack.pop();
                        }
                        stack.push(value);
                    }
                    else
                        cout<<"Stack is Empty!"<<endl;
                    break;
                    
                case '~':
                    if(!stack.isEmpty())
                    {
                        value=stack.top();
                        stack.pop();
                        stack.push(-value);
                    }
                    else
                        cout<<"Stack is Empty!"<<endl;
                    break;
                    
                case '$':
                    while(!stack.isEmpty())
                        stack.pop();
                    break;
                    
                
                case '.':
                    on=0;
                    break;
                        
                default:
                    cout<<"Unrecognized Operator!"<<endl;
                    break;
            }
        }
    }
    //end if input equals period
    while(on);
    
    return 0;
}