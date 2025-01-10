#include <iostream>
using namespace std;

int main()
{
    cout<<"Factorial Program\n";
    
    int num;
    cout<<"Enter the number whose factorial you wish to find: ";
    cin>>num;

    int fact = 1;

    for(int i = 1; i<=num; i++){
        fact = fact * i;
    }

    cout<<"The factorial of "<<num<<" is "<<fact<<"\n";
    return 0;
}