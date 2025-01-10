#include <iostream>
using namespace std;

// #define PI 3.14;

int main(){
    
    float radius;

    cout<<"Enter the radius of the circle: ";
    cin>>radius;

    double area = 3.14*(radius*radius);  
    cout<<"Area of circle is "<<area<<"\n";

    double circum = 2*3.14*radius;
    cout<<"Circumference of the circle is "<<circum<<"\n";

    return 0;

}