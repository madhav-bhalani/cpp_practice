#include <iostream>
using namespace std;

class Complex{
    private:
        int real, imag;

    public:
        Complex(int r = 0, int i = 0){
            real = r;
            imag = i;
        } 

        void print(){
            cout<<real<<" + "<<imag<<"i"<<endl;
        }

        Complex operator +(Complex c){
            Complex temp;
            temp.real = real + c.real;
            temp.imag = imag + c.imag;
            return temp;
        }
};

int main()
{
    Complex c1(2,4);
    Complex c2(1,2);
    Complex c3;
    Complex c4;

    c1.print();
    c2.print();

    c3 = c1 + c2;

    c3.print();

    c4 = c1+c2+c3;

    c4.print();
    return 0;
}