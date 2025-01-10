#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    // string fname, lname;
    // cout<<"Enter your first name:\n";
    // getline(cin,fname);
    // cout<<"Enter your last name:\n";  
    // getline(cin,lname);
    
    // lname[0] = 'l';

    // string name = fname+" "+lname;
    // cout<<"Your full name is "<<name<<"\n";
    
    cout<<"Enter your string here: \n";
    string str;
    getline(cin,str);

    string rev(str.rbegin(), str.rend());


    // string::reverse_iterator it;
    
    // char rev[] = "";

    // for(it = str.rbegin();it != str.rend();it++){
      
    // }
    
    if(rev==str){
        cout<<"The given string is palindrome!!\n";
    }
    else{
        cout<<"The given string is not palindrome..\n";
    }
    return 0;
}