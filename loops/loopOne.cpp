#include <iostream>
using namespace std;

int main()
{
    int i;
    //while loop
    cout<<"while loop:\n";
     while(i<=5){
        cout<<i<<"\n";
        i++;
    }

    //dowhile
    int z;
    cout<<"do while loop:\n";
    do{
       z++;
        cout<<z<<"\n";
         
    }
    while(z<=2);

    //for loop
    for(int x=1; x<=3; x++){
        cout<<"this is value of x: "<<x<<"\n";
    }

    return 0;
}