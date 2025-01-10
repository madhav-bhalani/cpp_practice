#include <iostream>
using namespace std;

int linearSearch(int a[], int n, int k){
    for(int i = 0; i<a[n]; i++){
        if(a[i]==k){
            return i;
        }
    }
}

int main()
{

    int (*fp) (int[], int, int);

    fp = linearSearch;

    int arr[] = {12,44,5,8,10,34};

    int key;
    cout<<"Enter the element you want to find:\n";
    cin>>key;
    int pos = fp(arr,6,key);
    if(pos>=0 && pos<6){
        cout<<"Element found at position "<<pos<<" in the array.\n";
    }
    else{
        cout<<"Element not present in the array.";
    }
    return 0;
}