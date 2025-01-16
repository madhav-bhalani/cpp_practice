#include <iostream>
using namespace std;

class Vehicle{
    public:

        // if a fucntion of parent class is declared as virtual then even if the pointer points 
        //to parent class,it will call the overrided function.
        virtual void start(){
            cout<<"Vehicle starting.."<<endl;
        }

        virtual void stop(){
            cout<<"Vehicle stopping.."<<endl;
        }
        virtual void horn(){
            cout<<"peep..peep.."<<endl;
        }
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
    // Vehicle v;
    // v.start();

    Vehicle *c = new Car();

    Vehicle *t = new Truck();


    c->start();
    c->horn();
    c->stop();

    t->start();
    t->stop();
    t->horn();


    
    return 0;
}