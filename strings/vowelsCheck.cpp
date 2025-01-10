#include<cstring>
#include<algorithm>
#include <iostream>
using namespace std;

int main()
{
    string s;
    int vowel, space, consonant;

    cout<<"Enter your string here: \n";
    getline(cin,s);

    string::iterator it;
    for(it=s.begin();it!=s.end();it++){
        if(*it=='A'||*it=='a'||*it=='e'||*it=='E'||*it=='o'||*it=='O'||*it=='u'||*it=='U'||*it=='i'||*it=='I'){
            vowel++;
        }
        else if(*it==' '){
            space++;
        }
        else{
            consonant++;
        }
    }

    cout<<"No. of vowels: "<<vowel<<"\n";
    cout<<"No. of spaces: "<<space<<"\n";
    cout<<"No. of consonants: "<<consonant<<"\n";
    return 0;
}