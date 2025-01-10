#include <iostream>
using namespace std;

int main()
{
    int a[10] = {3,6,23,5,27,12,87,22,17,10};

    bool  search = false;

    int n;
    cout<<"Enter the number you want to find: ";
    cin>>n;

    int i; 
    for(i = 0; i<10; i++){
    //    if(n==a[i]){
    //     search = true;
    //    }
        if(n==a[i]){
            cout<<"Number "<<n<<" found at position "<<i<<" in the array\n";
            return 0;
        }
        
    }
    cout<<"Number "<<n<<" is not present in the array.\n";
    // if(search){
    //     cout<<"Number "<<n<<" found at position "<<i<<" in the array.\n";
    // }
    // else{
    //     cout<<"Number "<<n<<" not present in the array.\n";
    // }
    return 0;
}