#include <iostream>
using namespace std;

int add(int x, int y, int z = 0){
    return x+y+z;
}

int max(int a = 0, int b = 0, int c = 0){
    return a>b && a>c ? a: (b>c?b:c);
}

int main()
{
    cout<<add(1,2,3)<<"\n";
    cout<<add(2,5)<<"\n";

    cout<<max()<<"\n";
    cout<<max(12)<<"\n";
    cout<<max(1,5)<<"\n";
    cout<<max(3,7,10)<<"\n";
    return 0;
}