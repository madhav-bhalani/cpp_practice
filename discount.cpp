#include <iostream>
using namespace std;

int main()
{
    float billAmount;
    float discountAmount;

    cout<<"Enter your bill amount here: \n";
    cin>>billAmount;

    if(billAmount>=100 && billAmount<500){
        discountAmount = (billAmount*10.0)/100.0;
        cout<<"Total Bill: "<<billAmount<<"₹\n";
        cout<<"Discount: "<<discountAmount<<"₹\n";
        cout<<"Discounted Price: "<<billAmount-discountAmount<<"₹\n";
    }


    if(billAmount<100){

        discountAmount = 0.00;
        cout<<"Total Bill: "<<billAmount<<"₹\n";
        cout<<"Discount: "<<discountAmount<<"₹\n";
        cout<<"Discounted Price: "<<billAmount-discountAmount<<"₹\n";
    }
    else if(billAmount>=500){
       discountAmount = (billAmount*20.0)/100.0;
        cout<<"Total Bill: "<<billAmount<<"₹\n";
        cout<<"Discount: "<<discountAmount<<"₹\n";
        cout<<"Discounted Price: "<<billAmount-discountAmount<<"₹\n";
    }

    return 0;
}