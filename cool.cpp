#include <iostream>
using namespace std;


int main()
{
    int n;
    int sum;
    cout<<"Enter the value of n: \n";
    cin>>n;

    for(int i = 0; i<=n; i++){
        sum = sum + n;
    }

    cout<<"The sum of first "<<n<<"natural numbers is "<<sum;
    return 0; 
}