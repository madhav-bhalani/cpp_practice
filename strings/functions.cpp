#include<cstring>
#include <iostream>
using namespace std;

int main()
{
    char s[100];
    cout<<"Enter your string: \n";
    cin.getline(s,100);

    cout<<"Length of string is: "<<strlen(s)<<"\n";
 
    char str1[100] = "ChillGuy";
    char str2[100] = "Guy";
    strcat(str1,str2);

    cout<<str1<<"\n";

    
    // char str3[100];
    // strcpy(str3,str1);

    // cout<<str3<<"\n";


    cout<<"STRSTR FUNCTION\n";
     cout<< strstr(str1,str2)<<"\n";

    cout<<strrchr("Programming", 'm')<<"\n";

    cout<<strcmp(s,str2)<<"\n";

    char st1[100] = "237";
    char st2[100] = "45.78";

    int x = strtol(st1, NULL, 10);
    float y =  strtof(st2,NULL);

    cout<<x<<"\n"<<y<<"\n";

     return 0;

}
