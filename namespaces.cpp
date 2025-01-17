#include <iostream>
using namespace std;

namespace First{
    void fun(){
        cout<<"First fun"<<endl;
    }
};

namespace Second{
    void fun(){
        cout<<"Second fun"<<endl;
    }
};

// this will make the First namespace as default
// i.e if no specific namespace is given and we call fun() without scope resolution, then it will be called.
using namespace First;

int main()
{   
    // First::fun();
    
    Second::fun();

    fun();

    return 0;
}