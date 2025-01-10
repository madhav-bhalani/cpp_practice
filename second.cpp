#include <iostream>
using namespace std;

int main(){

    string name;

    cout<<"Enter your name:\n";

    // cin>>name;
    getline(cin,name);

    cout<<name;

    return 0;

}