#include <iostream>
using namespace std;

int main()
{
    int marks[5];
    float sum = 0.00;
    cout<<"Enter your marks: \n";
    for(int i = 1; i<=5; i++){
        cout<<"Subject "<<i<<": ";
        cin>>marks[i];
        cout<<"\n";
        sum += marks[i];
    } 

    cout<<"Your total is "<<sum<<" out of 500 which is equivalent to "<<sum/5.0<<"%";
    
    return 0;
}