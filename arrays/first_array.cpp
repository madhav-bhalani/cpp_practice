#include <iostream>
using namespace std;

int main()
{
    char a[10] = {1,11,2,5,78,3,'a','r',45,10};

    cout<<"The first element is "<<a[0]<<"\n";

    cout<<"The elements of array are: \n";
    // for(int i = 0; i<10; i++){
    //     cout<<"a["<<i<<"]"<<" = "<<a[i]<<"\n";
    // }

    //fetching array elements using for each loop
    for(int i:a){
        cout<<i<<"\n";
    }

    return 0;
}