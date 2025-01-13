#include <iostream>
using namespace std;

class Rectangle{
    private:
        int len;
        int bre;

    public:
        Rectangle(int len, int bre){
            this->len = len;
            this->bre = bre;
        }

        int area(){
            return len * bre;
        }
};

int main()
{   
    Rectangle r(2,5);

    cout<<"Area is "<<r.area()<<endl;    
    return 0;
}