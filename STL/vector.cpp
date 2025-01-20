#include<list>
#include <iostream>
using namespace std;

int main()
{
    
    list <int> v;
    v = {12,45,67,89};

    //vector elements before push
    for(int x:v){
        cout<<x<<" ";
    }

    cout<<endl;

    //vector elements after push
    v.push_front(11);
    v.push_back(34);
    v.push_back(25);
    for(int x:v){
        cout<<x<<" ";
    }


    cout<<endl;

    //vector elements after pop
    v.pop_back();
    v.pop_front();
    for(int x:v){
        cout<<x<<" ";
    }

    return 0;
}