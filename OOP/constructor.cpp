#include <iostream>
using namespace std;

class Rectangle{
    //making data members private
    private: 
        float length, breadth;

    public: 
        //default/non-parameterized constructor 
        Rectangle();

        //parameterized constructor
        //by giving default values, it also works as a default constructor
        Rectangle(float l = 0, float b = 0);

        //copy constructor
        Rectangle(Rectangle &rect);
        //mutators
        void setLength(float l);
        void setBreadth(float b);


        //accessors defined as inline functions
        float getLength(){
            return length;
        }
        float getBreadth(){
            return breadth;
        }

        //facilitator functions
        float area();
        float perimeter();

        //inspector functions
        bool isSquare(); 

        //destructor
        ~Rectangle();


};



int main()
{   
    Rectangle r (4,3);
    // Rectangle *r = new Rectangle(12,4);
    Rectangle r1(r);

    // r->setLength(-4);
    // r->setBreadth(21);

    cout<<"Length: "<<r.getLength()<<endl;
    cout<<"Breadth: "<<r.getBreadth()<<endl;

    cout<<"Area: "<<r.area()<<endl;
    cout<<"Perimiter: "<<r.perimeter()<<endl;

    cout<<"area of copy rec: "<<r1.area()<<endl<<"perimeter of copy rec: "<<r1.perimeter()<<endl;
    
    cout<<"Is it a square? "<<endl;
    if(r.isSquare()){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }

    return 0;
}


//use of scope resolution operator
Rectangle::Rectangle(){
    length = 0;
    breadth = 0;
}

Rectangle::Rectangle(float l, float b){
            setLength(l);
            setBreadth(b);
        }

Rectangle:: Rectangle(Rectangle &rect){
            length = rect.length;
            breadth = rect.breadth;
        }


float Rectangle::area(){
     return length * breadth;
}
float Rectangle::perimeter(){
      return 2 * (length + breadth);
}

void Rectangle::setLength(float l){
        if(l >= 0){
            length = l;
        }
        else{
            cout<<"Length cannot be in negative."<<endl;
            // length = 0;
        }
    }
void Rectangle::setBreadth(float b){
            if(b >= 0){
                breadth = b;
            }
            else{
                cout<<"Breadth cannot be in negative"<<endl;
                // breadth = 0;
            }
        }

bool Rectangle::isSquare(){
    return length==breadth;
}

Rectangle::~Rectangle(){
    cout<<"Destructor called.."<<endl;
}