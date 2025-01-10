#include<string>
#include <iostream>
using namespace std;

int main()
{
    string s1 = "GoodGuy";

    char s[15];
    s1.copy(s,5);
    cout<<s<<"\n";
   

    string text = "They desperately needed another drummer since the current one only knew how to play bongos.";
    string key;
    cout<<"Enter the string you want to find: \n";
    // cin>>key;
    // cin.get(key);
    getline(cin,key);
    int pos = text.find(key);


    if(pos<=text.length()){
        cout<<"The word "<<key<<" present in the array and found at "<<pos<<" position in the array.\n";
    }
    else{
        cout<<"The word "<<key<<" is not present in the array..\n";
    }
    

    //substr program:

    string str = "Good Morning!!";

    cout<<str.substr(2,-1)<<"\n";


    
     return 0;
}