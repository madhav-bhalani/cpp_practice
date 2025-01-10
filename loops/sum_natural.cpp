#include <iostream>
using namespace std;

int main()
{
    cout<<"Sum of first n natural numbers\n";

    int n;
    cout<<"Enter the value of n: ";
    cin>>n;

    int sum;

    for(int i=1; i<=n; i++){
        sum = sum + i;
    }

    cout<<"The sum of first "<<n<<" natural numbers is: "<<sum<<"\n";
    return 0;
}