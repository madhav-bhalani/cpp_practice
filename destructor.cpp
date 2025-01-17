#include <iostream>
using namespace std;

class Demo{
    public:
        Demo(){
            cout<<"Constructor"<<endl;
        }

        ~Demo(){
            cout<<"Desctructor of Demo"<<endl;
        }
};

void fun(){
    Demo *p = new Demo;
}

int main()
{
    fun();
    return 0;
}