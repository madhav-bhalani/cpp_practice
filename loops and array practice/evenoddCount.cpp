#include <iostream>
using namespace std;

int main()
{
    cout<<"Enter the value of n:\n";
    int n;
    cin>>n;

    int odd, even;
    for(int i = 1; i <= n; i++){
        if(i%2==0){
            even++;
        }
        else{
            odd++;
        }
    }

    cout<<"There are total "<<odd<<" odd numbers and "<<even<<" even numbers between 1 "<<"and "<<n;
    return 0;
}