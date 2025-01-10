#include <iostream>
using namespace std;

int main()
{
    cout<<"Welcome to your calculator!!\n";
   
    int a, b;
    cout<<"Enter the value of a:\n";
    cin>>a;
    cout<<"Enter the value of b:\n";
    cin>>b;

    int choice;
    cout<<"Select the operation you want to perform:\n";
    cout<<"1. Add\n"<<"2. Sub\n"<<"3. Mul\n"<<"4. Div\n"<<"5. Modulo\n";
    cin>>choice;
    switch (choice)
    {
    case 1:
        cout<<"Result of "<<a<<" + "<<b<<" is "<<a+b<<"\n";
        break;
    case 2:
        cout<<"Result of "<<a<<" - "<<b<<" is "<<a-b<<"\n";
        break;
    case 3:
        cout<<"Result of "<<a<<" * "<<b<<" is "<<a*b<<"\n";
        break;
    case 4:
        cout<<"Result of "<<a<<" / "<<b<<" is "<<a/b<<"\n";
        break;
    case 5:
        cout<<"Result of "<<a<<" % "<<b<<" is "<<a%b<<"\n";
        break;
    default:
        cout<<"Invalid input\n";
        break;
    }

    return 0;
}