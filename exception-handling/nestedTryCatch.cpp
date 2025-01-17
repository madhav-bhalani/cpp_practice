#include<cstring>
#include <iostream>
using namespace std;

class MyException1: public exception{

};

class MyException2: public MyException1{

};

int main()
{
    try{
        throw MyException1();
    }    
    catch(MyException2 e){
        cout<<"Int caught: "<<endl;
    }
    catch(MyException1 e){
        cout<<"Char caught: "<<endl;
    }
    catch(float e){
        cout<<"Float caught: "<<e<<endl;
    }
    catch(string e){
        cout<<"String caught: "<<e<<endl;
    }


    return 0;
}