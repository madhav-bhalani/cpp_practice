#include <iostream>
#include <cmath>

using namespace std;



int main()
{
    int a, b, c, d;

    cout<<"Enter the values of a, b, c: \n";
    cin>>a>>b>>c;

    d = b*b - 4*a*c;

    if(d==0)
        cout<<"Roots are real and equal\n";
    else if(d>0)
        cout<<"Roots are real and unequal\n";
    else
        cout<<"Roots are imaginary\n";

    float r1 = (-b+sqrt(b*b - 4*a*c))/(2*a);
    float r2 = (-b-sqrt(b*b - 4*a*c))/(2*a);
    
    cout<<"The roots are "<<r1<<" and "<<r2;
    return 0;
}