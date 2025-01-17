#include <iostream>
using namespace std;

class Outer{
    public:
        void fun(){
            i.display();
        }
        class Inner{
            public:
                void display(){
                    cout<<"Display from inner"<<endl;
                }
        };
       
    Inner i;
};

int main()
{
    
    Outer o;
    o.fun();

    
    return 0;
}