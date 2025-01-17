#include <iostream>
using namespace std;

class Demo{
    private: 
        int x = 5;
        int y =2;
    
    public:

        // when void display() const { x++; cout; } here x++ won't work as declaring a function as const
        //will prevent any modification on variable x i.e it makes all the data members read-only;
        void display(){
            x++;
            cout<<x<<endl<<y;
        }
};

int main()
{
    int a = 5;

    // const int i = 0;

    // const int *const ptr = &a; 
    // ++*ptr;
    ++a;

    // i++; // because constant variables cannot be modified.

    // cout<<*ptr<<endl<<a;

    Demo d;
    d.display();

    return 0;
}