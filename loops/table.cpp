#include <iostream>
using namespace std;

int main()
{
    cout<<"Table System\n";

    int num;    
    cout<<"Enter any number: ";
    cin>>num;

    cout<<"The table of "<<num<<" is displayed below: \n";
    for(int i=1; i<=10; i++){
        cout<<num<<" * "<<i<<" = "<<num*i<<"\n";
    }
    return 0;
}