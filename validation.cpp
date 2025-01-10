#include<iostream>
using namespace std;

int main()
{
    int a,b,c;

    cout<<"Enter value of a: \n";
    cin>>a;
    cout<<"Enter value of b: \n";
    cin>>b;

    if(b<=0){
        cout<<"Invalid denominator (0 or negative integer) Division operation cannot be performed!!";
    }
    else{
        c = a / b;
        cout<<"The result obtained after division is "<<c<<"\n";
    }

    return 0;
}