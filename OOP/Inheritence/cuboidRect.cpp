#include <iostream>
using namespace std;

class Rectangle{
    private:
        int length;
        int breadth;

    public:
        //constructors
        Rectangle();
        Rectangle(int l, int b);
        // Rectangle(Rectangle &r);

        //accessor inline
        int getLength(){return length;};
        int getBreadth(){return breadth;};

        //mutators
        void setLength(int l);
        void setBreadth(int b);

        //facilitators
        float area();
        float perimeter();

        //inspectors
        bool isSquare();

        //destructor
        // ~Rectangle();


};

class Cuboid: public Rectangle{
    private:
        int height;
    
    public:
         Cuboid(int l, int b, int h) : Rectangle(l, b) {
        height = h;
    }

        int getHeight(){return height;}

        void setHeight(int h){ 
            h = height;
        }

        float volume(){
            return getLength() * getBreadth() * height;
        }
};

int main()
{
    Rectangle r(2,5);
    cout<<"Area of rectangle is "<<r.area()<<endl;
    cout<<"Perimeter of rectangle is "<<r.perimeter()<<endl;

    Cuboid c(r.getLength(), r.getBreadth(), 10);
    cout<<"Area of cuboid is "<<c.area()<<endl;
    cout<<"Volume of cuboid is "<<c.volume()<<endl;
    cout<<"Height of cuboid is "<<c.getHeight()<<endl;
    cout<<"Length of cuboid is "<<c.getLength()<<endl;
    cout<<"Breadth of cuboid is "<<c.getBreadth()<<endl;
    return 0;
}


Rectangle::Rectangle(){
    length = 1;
    breadth = 1;
}

Rectangle::Rectangle(int l, int  b){
    length = l;
    breadth = b;
}

void Rectangle::setLength(int l){
    l = length;
}

void Rectangle::setBreadth(int b){
    b = breadth;
}

float Rectangle::area(){
    return (length*breadth);
}

float Rectangle::perimeter(){
    return float(2 * (length + breadth));
}

bool Rectangle::isSquare(){
    if(length == breadth){
        return true;
    }
    else{
        return false;
    }
}

