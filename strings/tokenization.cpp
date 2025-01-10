#include<cstring>
#include <iostream>
using namespace std;

int main()
{
    char str[100] = "x=10;y=23;z=89.0;";

    char *token = strtok(str,"=");

    for(;token!=NULL;){
        cout<<token<<"\n";
        token = strtok(NULL,"=");
    }

    return 0;
}