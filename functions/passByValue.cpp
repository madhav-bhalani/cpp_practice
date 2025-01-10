#include <iostream>
using namespace std;

void swap(int &a, int &b)//formal parameters
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    // cout<<a<<" "<<b<<"\n";
}

int main()
{
    int x = 5, y = 7;
    //call by value
    // swap(x,y);//actual parameters;

    swap(x,y);

    cout<<x<<" "<<y;
    return 0;
}