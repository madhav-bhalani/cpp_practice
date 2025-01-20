#include <iostream>
#include<map>
using namespace std;

int main()
{
    map<int, string> m;
    m.insert(pair<int, string>(1, "madhav"));
    m.insert(pair<int, string>(2, "jeet"));
    m.insert(pair<int, string>(3, "aditya"));
    m.insert(pair<int, string>(4, "harsh"));

    map<int, string>::iterator itr;
    for(itr = m.begin(); itr!=m.end(); itr++){
        cout<<"id: "<<itr->first<<" name: "<<itr->second<<endl;
    }

    return 0;
}