#include <iostream>
using namespace std;

int main()
{
    int n = 5;
    for(int i = 1; i<=5; i++ ){
        for(int j = n; j > i; j--){
            cout<<"*";
        }
        cout<<" ";
        cout<<"\n";
    }
    return 0;
}