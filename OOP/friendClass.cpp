#include <iostream>
using namespace std;

class Exam;
class Test {
    private: int a = 10;
    protected: int b =15;
    public: int c = 20;
    friend Exam;
};

class Exam {
    public:

        Test t;

        void fun(){
            cout<<t.a<<endl;
            cout<<t.b<<endl;
            cout<<t.c<<endl;
        }
};

int main()
{

    Exam e;
    e.fun();

    return 0;
}