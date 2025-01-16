#include <iostream>
using namespace std;

class Vehicle{
    public:

       //by making all the functions virtual and assigning them to zero, we can make a class PURE VIRTUAL.

       virtual void start() = 0;
       virtual void stop() = 0;
       virtual void horn() = 0;
};

class Car: public Vehicle{
    public: 
        void start(){
            cout<<"Car starting.."<<endl;
        }

        void stop(){
            cout<<"Car stopping.."<<endl;
        }

        void horn(){
            cout<<"Car peep..peep.."<<endl;
        }
};

class Truck: public Vehicle{
    public:
        void start(){
            cout<<"Truck starting.."<<endl;
        }
        void stop(){
            cout<<"Truck stopping.."<<endl;
        }

        void load(){
            cout<<"Loading goods.."<<endl;
        }
        void horn(){
            cout<<"Truck peep..peep.."<<endl;
        }
};

int main()
{   
    // we cannot create an object of a pure virtual class.
    // Vehicle v;
    // v.start();

    Vehicle *v = new Car();
    v->start();
    v->horn();
    v->stop();

    v = new Truck();
    v->start();
    v->stop();
    v->horn();


    
    return 0;
}