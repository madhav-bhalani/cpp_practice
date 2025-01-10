#include <iostream>
using namespace std;

int main()
{
    int a[5];

    cout<<"Enter values in the array: \n";
    for(int i = 0; i<5; i++){
        cout<<"a["<<i<<"] = ";
        cin>>a[i];
        cout<<"\n";
    }

    cout<<"The elements of array in reverse order:\n";
    for(int i = 4; i>=0; i-- ){
        cout<<a[i]<<" ";
    }
    return 0;
}