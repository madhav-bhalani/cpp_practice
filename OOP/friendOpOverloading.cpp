#include <iostream>
using namespace std;

class Complex{
    private: 
        int real;
        int imag;
    
    public: 
        Complex(int r = 0, int i = 0){
            real = r;
            imag = i;
        }

        void display(){
            cout<<real<<" + "<<imag<<"i"<<endl;
        }

        friend Complex operator +(Complex c1, Complex c2);
};

Complex operator +(Complex c1, Complex c2){
    Complex t;
    t.real = c1.real + c2.real;
    t.imag = c1.imag + c2.imag;
    return t;
}




int main()
{
    Complex c1(2,4);
    Complex c2(3,5);

    Complex c3;
    c1.display();
    c2.display();
    c3 = c1 + c2;
    c3.display();
    return 0;
}