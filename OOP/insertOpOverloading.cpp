#include <iostream>
using namespace std;

class Complex{
    private:
        int real, img;

    public:
        Complex(int r, int i){
            real = r;
            img = i;
        }

        friend ostream & operator <<(ostream &o, Complex &c);
};

ostream & operator <<(ostream &o, Complex &c){
    o<<c.real<<"+i"<<c.img<<endl;
    return o;
}

int main()
{
    
    Complex c1(2,4);
    Complex c2(4,6);

    cout<<c1;
    cout<<c2;
    return 0;
}