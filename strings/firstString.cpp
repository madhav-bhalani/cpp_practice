#include <iostream>
using namespace std;

int main()
{
    char s[10] = "Madhav";

    cout<<s<<"\n";

    // char *p = "cool";

    char str[20];
    cout<<"Enter your name: ";
    cin.getline(str,20);
    cout<<str<<"\n";


    return 0;
}