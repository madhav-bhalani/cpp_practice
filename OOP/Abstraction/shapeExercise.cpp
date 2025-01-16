#include <iostream>
using namespace std;

class Shape{
    virtual float area() = 0;
    virtual float perimeter() = 0; 
};

class Rectangle: public Shape{
    private: 
        float length, breadth;

    public: 
        //constructor
        Rectangle(float l, float b){
            if(l>0){
                length = l;
                breadth = b;
            }
            else{
                cout<<"ERROR: Negative values not allowed"<<endl;
                length = 0;
                breadth = 0;
            }

        }

        float area(){
            return length * breadth;
        }

        float perimeter(){
            return 2*(length+breadth);
        }
 };

 class Circle: public Shape{
    private:
        float radius;

    public:
        //constructor
        Circle(float r){
            if(r>0){
                radius = r;
            }
            else{
                cout<<"ERROR: Negative values not allowed"<<endl;
                radius = 0;
            }
        }

        float area(){
            return 3.14 * radius * radius;
        }

        float perimeter(){
            return 2 * 3.14 * radius;
        }

 };


int main()
{
    float l, b, r;

    cout<<"Enter length of rectangle:"<<endl;
    cin>>l;
    cout<<"Enter breadth of rectangle:"<<endl;
    cin>>b;
    Rectangle rect(l, b);
    cout<<"Area of rectangle is "<<rect.area()<<endl;
    cout<<"Perimeter of rectangle is "<<rect.perimeter()<<endl;

    cout<<"Enter radius of circle:"<<endl;
    cin>>r;
    Circle c(r);
    cout<<"Area of circle is "<<c.area()<<endl;
    cout<<"Perimeter of circle is "<<c.perimeter()<<endl; 
    
    return 0;
}