#include<cstring>
#include<algorithm>
#include <iostream>
using namespace std;

int main()
{

    string str = "Welcome";
    // cout<<"Length: "<<str.length()<<"\n";
    int count = 0;
    // for(int i=0; str[i]!='\0';i++){
    //     count = count + 1;
    // }
    
    // cout<<"The length of the string is "<<count<<"\n";

    //using iterator
    string::iterator it;
    for(it=str.begin();it!=str.end();it++){
        count++;
    }

    cout<<"The length of the string is "<<count<<"\n";

    return 0;


}