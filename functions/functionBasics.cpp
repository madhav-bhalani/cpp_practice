#include <iostream>
using namespace std;

void display(){
    cout<<"A simple function with no return value";
}

int add(int n1, int n2){
    return n1 + n2;

}

int main()
{
    cout<<"Enter two numbers: \n";
    int num1, num2;
    cin>>num1>>num2;
    cout<<"The sum of "<<num1<<" and "<<num2<<" is "<<add(num1,num2)<<"\n";
    display();
    return 0;
}