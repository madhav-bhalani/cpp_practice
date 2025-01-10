#include<string>
#include <iostream>
using namespace std;

int main()
{
    string s;
    cout<<"Enter any string:\n";
    getline(cin,s);
    cout<<s<<"\n";

    s.append("bhalani");
    cout<<"full name is :"<<s<<"\n";

    s.insert(6," ");
    cout<<s<<"\n";

    string s2 = "Object Oriented";
    s2.replace(5,3,"oop");
    cout<<s2<<"\n";

    string s3 = "oriented";
    s3.push_back('s');
    cout<<s3<<"\n";
    s3.pop_back();
    cout<<s3<<"\n";

    s2.swap(s3);
    cout<<s2<<"\n";
    return 0;
}