#include <iostream>
using namespace std;

class Test{
    private: int a, b;

    public:
        static int c;
        void test(){
             a = 5;
             b = 10;
             c++;
        }


        // static function
        static int getCount(){
            // a++; // you can only use static data members inside a static function.
            return c;
        }
};

int Test::c = 0;

int main()
{
    Test t1;
    Test t2;



    t1.test();
  
    t2.test();
    
   cout<<t1.Test::getCount();
  
    return 0;
}