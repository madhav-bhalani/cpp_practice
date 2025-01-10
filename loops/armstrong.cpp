#include<iostream>

using namespace std;

void Armstrong(int n)
{
    int sum=0,r;
    int m=n;
    
    for(;n!=0;){
        r = n % 10;
        n = n / 10;
        sum = sum + r*r*r;
    }
    //write a loop to find sum of cubes of digits
    //check if a number is Armstrong
    
     if(sum==m)
        cout<<"armstrong";
    else
        cout<<"not armstrong";
}

int main(){
    Armstrong(153);
}