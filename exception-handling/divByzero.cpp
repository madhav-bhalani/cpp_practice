#include <iostream>
using namespace std;

//exception Class
class MyException: public exception{

};




//new function
int division(int a, int b){
    if(b==0)
        throw MyException();
    return a/b;
}

int main()
{
    int x=10, y = 0, z;

    try{
        // if(y==0){
        //     throw 1;
        // }

        z = division(x,y);
        cout<<z;
    }

    catch(MyException e){
        cout<<"DIVISION BY ZERO.."<<endl;
    }

    return 0;
}