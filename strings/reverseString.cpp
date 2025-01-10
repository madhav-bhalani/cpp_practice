#include<cstring>
#include<algorithm>
#include <iostream>
using namespace std;

int main()
{
    string s1 = "palindrome";

    string::reverse_iterator it;

    for(it=s1.rbegin();it!=s1.rend();it++){
        cout<<*it<<"\n";
    }

    return 0;
}