#include <iostream>
using namespace std;

int main()
{
    int n;

    cout<<"Enter the value of n:\n";
    cin>>n;

    for(int i = 0; i<=n;i++){
        if(i%i==0 || i%1==0){
            cout<<i<<" ";
        }
    }
    return 0;
}