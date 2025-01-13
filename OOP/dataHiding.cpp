#include <iostream>
using namespace std;

class Rectangle{
    //making data members private
    private: 
        float length, breadth;

    public: 
        void setLength(float l){
            if(l >= 0){
                length = l;
            }
            else{
                cout<<"Length cannot be in negative."<<endl;
                length = 0;
            }
        }
        void setBreadth(float b){
            if(b >= 0){
                breadth = b;
            }
            else{
                cout<<"Breadth cannot be in negative"<<endl;
                breadth = b;
            }
        }

        float getLength(){
            return length;
        }
        float getBreadth(){
            return breadth;
        }

        float area(){
            return length * breadth;
        }
        float perimeter(){
            return 2 * (length + breadth);
        }
};

int main()
{   
    Rectangle *r = new Rectangle();

    r->setLength(-4);
    r->setBreadth(21);

    cout<<"Length: "<<r->getLength()<<endl;
    cout<<"Breadth: "<<r->getBreadth()<<endl;

    cout<<"Area: "<<r->area()<<endl;
    cout<<"Perimiter: "<<r->perimeter()<<endl;
    
    return 0;
}