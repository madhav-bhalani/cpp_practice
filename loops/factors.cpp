#include <iostream>
using namespace std;

int main()
{
    cout<<"Factors Program\n";

    int n;
    cout<<"Enter any number: ";
    cin>>n;

   int sum = 0;

   int count = 0;
    for(int i = 1; i <= n; i++){
       
        if(n % i == 0){
             count++;
            if(i != n){
                sum = sum + i;
            }
            cout<<i<<",";
        }
    }
    cout<<" are factors of "<<n<<"\n";

    if(count == 2){
        cout<<n<<" is a prime number\n";
    }
    else{
        
        cout<<n<<" is not a prime number\n";
    }
    
    if(sum == n){
        cout<<n<<" is a perfect number\n";
    }
    else{
        cout<<n<<" is not a perfect number\n";
    }
    return 0;
}