#ifndef PI
    #define PI 3.1427
#endif
#include <iostream>
#define c cout
#define sqr(x)(x*x)
#define msg(x) #x
using namespace std;

int main()
{
    c<<"hello"<<endl;

    c<<"5 * 5 = "<<sqr(5)<<endl;

    c<<msg(okay right);
    return 0;
}