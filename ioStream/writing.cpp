#include<fstream>
#include<cstring>
#include <iostream>
using namespace std;

int main()
{

    string content;

    ofstream outfile("myfile.txt", ios::trunc);
    

    cout<<"Enter the content you wish to add in the file:"<<endl;
    getline(cin, content);

    outfile<<content<<endl;

    // outfile<<"maddy"<<endl;
    // outfile<<"cool"<<endl;

    outfile.close();



    return 0;
}