#include<cstring>
#include<algorithm>
#include <iostream>
using namespace std;

int main()
{
    cout<<"Enter the string here: "<<"\n";
    string str;
    getline(cin,str);

    for(char &c: str){
        if(isupper(c)){
            c += 32;
        }
        else if(islower(c)){
            c -= 32;
        }
    }

    cout<<str<<"\n";

    
    return 0;
}