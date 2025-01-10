#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int &y = a;

    a++;
    y++;
    cout<<a;
    return 0;
}