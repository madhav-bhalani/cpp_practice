#include <iostream>
using namespace std;

int main()
{
    int a[10] = {2,12,14,20,22,25,39,56,79,90};

    int low = 0, high = 9;
    int mid = low+high / 2;

    cout<<"Enter the number you want to search: ";
    int key;
    cin>>key;
    // cout<<key;

    for(;low<=high;){
        if(key == a[mid]){
            cout<<"Number "<<key<<" found at position "<<mid<<" in the array.\n";
            return 0;
        }
        else if(key > a[mid]){
            low = mid + 1;
            mid = low+high / 2;

        }
        else if(key < a[mid]){
            high = mid - 1;
            mid = low+high / 2;

        }
    }
    cout<<"Number "<<key<<" not present in array\n";
    return 0;
}