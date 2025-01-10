#include <iostream>
using namespace std;

int main()
{
    int num1, num2;

    cout<<"Enter number 1: \n";
    cin>>num1;
    cout<<"Enter number 2: \n";
    cin>>num2;

    for(;num1!=num2;){
        if(num1>num2){
            num1 = num1 - num2;
        }
        else if(num2>num1){
            num2 = num2 - num1;
        }
    }    

    cout<<"G.C.D of two numbers is "<<num1<<"\n";
    return 0;
}