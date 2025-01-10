#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
    string mail;

    cout<<"Enter your e-mail id:\n";
    cin>>mail;

    int a = mail.find("@");

    cout<<"Your username is "<<mail.substr(0,a);

    return 0;
}