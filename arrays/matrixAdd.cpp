#include <iostream>
using namespace std;

int main()
{
    int a[2][3]={1,2,3,4,5,6};
    int b[2][3]={1,1,1,1,1,1};
    int sum[2][3];

    cout<<"ADDITION OF TWO-DIMENSIONAL  MATRIX:\n";

    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            sum[i][j] = a[i][j] * b[i][j];
        }
    }

    cout<<"The values obtained in new matrix after addition:\n";
    for(auto& x:sum){
        for(auto& y:x){
            cout<<y<<"\n";
        }
    }
    return 0;
}