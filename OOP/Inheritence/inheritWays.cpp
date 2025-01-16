#include <iostream>
using namespace std;

class Parent{
    private: int a;
    protected: int b;
    public: int c;
        
        void funParent(){
                a = 10;
                b = 20;
                c = 30;
        }

};

class Child: public Parent{
    public:
        void funChild(){
            // a  = 5; //Child class derived as public so only protected and public data members are accessible.
            b = 15;
            c = 25;
        }
};

class GrandChild: private Child{
    public:
        void funGrandChild(){
            // a = 20;
            b = 30;
            c = 40;
        }
};

int main()
{
    
    return 0;
}