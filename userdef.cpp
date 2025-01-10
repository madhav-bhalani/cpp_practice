#include<iostream>
using namespace std;

typedef int marks;

// enum day {mon=1,tue, wed, thur, fri, sat, sun};
int main(){
    //enum example 
    // day d;
    // d = fri;

    // cout<<d;

    //typedef example
    marks m1,m2,m3;
    cout<<"Enter the marks: \n";
    cin>>m1>>m2>>m3;

    int sum = m1 + m2 + m3;

    float avg = sum/3;

    cout<<"The percentage based on marks is "<<avg<<"%";


}