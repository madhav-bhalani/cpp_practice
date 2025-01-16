#include <iostream>
using namespace std;

class Base{
    public:
        void display(){
            cout<<"This is coming from base class"<<endl;
        }
        
};

class Derived: public Base{
    public:
        void show(){
            cout<<"This is coming from derived class"<<endl;
        }
};

int main()
{
    Base b1 = Base();
    Derived d1 = Derived();

    b1.display();
    d1.show();
    d1.display();
    return 0;
}