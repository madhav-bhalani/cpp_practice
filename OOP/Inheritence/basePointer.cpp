#include <iostream>
using namespace std;

class Base{
    public:
        void fun1(){
            cout<<"Function 1 Base class"<<endl;
        }

        void fun2(){
            cout<<"Function 2 Base class"<<endl;
        }
        void fun3(){
            cout<<"Function 3 Base class"<<endl;
        }
};

class Derived: public Base{
    public:
        void fun4(){
            cout<<"Function 4 Derived class"<<endl;
        }

        void fun5(){
            cout<<"Function 5 Derived class"<<endl;
        }
};

int main()
{
    
    Base *p =  new Derived();

    p->fun1();
    p->fun2();
    p->fun3();

    //the pointer to a Base Class can only access the Base Class functions..
    // p->fun4(); 
    // p->fun5();

    return 0;
}