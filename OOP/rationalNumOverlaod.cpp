#include <iostream>
using namespace std;

class Rational{
    private:
        int p;
        int q;
    
    public: 
         Rational(){
            p = 0;
            q = 1;
        }
        Rational(int p, int q){
            this->p = p;
            this->q = q;
        }

        // void display(){
        //     cout<<p<<" / "<<q<<endl;
        // }

        friend Rational operator +(Rational r1, Rational r2);

        //insertion operator overloading
        friend ostream & operator<<(ostream &out, Rational r);

};

Rational operator +(Rational r1, Rational r2){
    Rational temp;
    temp.p = r1.p + r2.p;
    temp.q = r1.q + r2.q;
    return temp;
}

ostream & operator<<(ostream &out, Rational r){
    out<<r.p<<" / "<<r.q<<endl;
    return out;
}

int main()
{
    Rational r1(2,4);
    Rational r2(5,3);



    // r1.display();
    // r2.display();

    Rational r3;
    r3 = r1 + r2;
    // r3.display();
    cout<<r1;
    cout<<r2;
    cout<<r3;
    return 0;
}