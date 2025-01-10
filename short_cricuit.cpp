#include <iostream>
using namespace std;

int main()
{
    int a = 10, b = 5, c = 5;

    if(a>b || ++c<=b){
     cout<<b;
    }

    //dynamic declaration

    if(a>b){

        int k = a+b;
        cout<<k;
    }


    return 0;
}