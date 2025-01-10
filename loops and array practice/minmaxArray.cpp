#include <iostream>
using namespace std;

int main()
{
    int a[5] = {12,56,11,7,9};
    int min = 12, max = 12;
    
    for(int i = 0; i<5; i++){
        if(a[i] <= min){
            min = a[i];
        }
        else if(a[i] >= max){
            max = a[i];
        }
    }

    cout<<"The maximum number in the array is "<<max<<"\n";
    cout<<"The minimum number in the array is "<<min<<"\n";
    return 0;
}