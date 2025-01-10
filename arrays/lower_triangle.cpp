#include <iostream>
using namespace std;

int main()
{ 
    int n = 5;

    //cross lower triangle
   
    for(int i = 0; i<n; i++){
        for(int j = 0 ; j<n; j++){
            if(i+j > n-1){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}