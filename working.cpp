#include <iostream>
using namespace std;

int main()
{
    int hour;

    cout<<"Enter the time in hours: \n";
    cin>>hour;

    if(hour >= 9 && hour <= 18){
        cout<<"DO NOT DISTURB!! these are working hours..";
    }
    else{
        cout<<"These are leisure hours :)";
    }

    return 0;
}