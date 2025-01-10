#include <iostream>
using namespace std;

int main()
{
    int a[2][3];

    cout<<"Enter the values for a 2x3 array:\n";
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
          cout<<"Enter value of ["<<i<<"]["<<j<<"]:";
          cin>>a[i][j];
          cout<<"\n";
        }
    }

    cout<<"The elements of the arrays are:\n";
    for(auto& x:a){
       for(auto& y:x){
            cout<<y<<"\n";
        }
    }
    return 0;
}
