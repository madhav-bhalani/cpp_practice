#include <iostream>
using namespace std;


int main()
{
    int n;
    int sum = 0;
    cout<<"Enter the value of n: \n";
    cin>>n;

    for(int i = 1; i<=n; i++){
        sum = n * (n+1) / 2;
    }

    cout<<"The sum of first "<<n<<" natural numbers is "<<sum;
    return 0; 
}