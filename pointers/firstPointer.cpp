#include <iostream>
using namespace std;

int main()
{
    // int a = 10;
    // int *p = &a;

    // cout<<a<<endl;
    // cout<<&a<<endl;
    // cout<<p<<endl;
    // cout<<&p<<endl;
    // cout<<*p<<endl;

    int *p = new int[3];

    p[0] = 12;
    p[2] = 11;
    p[1] = 25;
    // cout<<p[0]<<p[1]<<p[2];

    p = nullptr;

   // cout<<p[0]; // segmentation fault: accessing a segment of memory that doesn;t belong to me.
    return 0;
}