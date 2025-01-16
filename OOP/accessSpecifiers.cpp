#include <iostream>
using namespace std;

class Base{
    private:
        int a;
    protected:
        int b;
    public:
        int c;

        void funBase(){
            a = 10;
            b = 15;
            c = 20;
        }

};

class Child: public Base{
    private:
        int d = 5;
    public:
        int h = 50;

        void childFun(){
            b = 32;
            cout<<b;
        }
};

int main()
{
    Base b;
    b.funBase();
    // cout<<b.a<<endl;
    // cout<<b.b<<endl;
    cout<<b.c<<endl;

    Child c;
    c.childFun();

    
    return 0;
}