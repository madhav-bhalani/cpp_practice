#include <iostream>
using namespace std;

int main()
{
    cout<<"Program to display the digits of your number\n";

    int r, num;
    cout<<"Enter your number: ";
    cin>>num;

    for(;num!=0;){
        r = num % 10;
        num = num / 10;
        cout<<r<<"\n";
    }

    return 0;
}