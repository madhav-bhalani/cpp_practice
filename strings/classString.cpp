#include <iostream>
#include<string>
using namespace std;

int main()
{

    string str;
    cout<<"Enter your name: ";
    getline(cin,str);

    cout<<"\n"<<str;

    cout<<"The length of string is "<<str.length()<<"\n";
    cout<<"The size of string is "<<str.size()<<"\n";

    cout<<"The capacity of string before resize is "<<str.capacity()<<"\n";

    str.resize(30);
    cout<<"The capacity of string after resize is "<<str.capacity()<<"\n";

    cout<<"The maximum size supported for string by the compiler is "<<str.max_size()<<"\n";
    
    cout<<"is the string empty? "<<str.empty()<<"\n";

    str.clear();
    cout<<"is the strig empty? "<<str.empty()<<"\n";
   
    return 0;
}