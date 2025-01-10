#include <iostream>
using namespace std;

int main()
{
    cout<<"PALINDROME CHECKER\n";
   
    int num;
    cout<<"Enter any number: ";
    cin>>num;
    int m = num;

    int r, rev=0;

    for(;num!=0;){
        r = num % 10;
        num = num / 10;
        rev = rev * 10 + r;
    }

    cout<<"The reverse of the number "<<m<<" is "<<rev<<".\n";

    if(m == rev){
        cout<<"The number "<<m<<" is a palindrome.\n";
    }
    else{
        cout<<"The number"<<m<<" is not a palindrome.\n";
    }

    return 0;
}