#include <iostream>
using namespace std;

class Rectangle{
    public: 

        float length;
        float breadth;

        float area(){
            return length * breadth;
        }

        float perimeter(){
            return 2 * (length + breadth);
         }


};

int main()
{
    //creating objects in stack memory
    // Rectangle r1, r2;
    
    // r1.length = 11.4;
    // r2.length = 5.78;

    // r1.breadth  = 5.3;
    // r2.breadth = 15;

    // cout<<"Area of rectangle 1 is "<<r1.area()<<"\n";
    // cout<<"Area of rectangle 2 is "<<r2.area()<<"\n";

    // cout<<"Perimeter of rectangle 1 is "<<r1.perimeter()<<"\n";
    // cout<<"Perimter of rectangle 2 is "<<r2.perimeter()<<"\n";

    //using pointer
    // Rectangle r1, *r;
    // r = &r1;

    // r->length=12;
    // r->breadth=3.5;

    // cout<<"Area of rectangle is "<<r->area()<<"\n"; 

    //creating objects in heap memory with pointers
    Rectangle *r = new Rectangle();

    r->length=12.65;
    r->breadth=4.7;

    cout<<"Area = "<<r->area()<<" and Perimeter = "<<r->perimeter()<<"\n";


    return 0;
}