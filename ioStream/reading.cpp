#include<fstream>
#include<cstring>
#include <iostream>
using namespace std;

int main()
{   
    string c1, c2, c3;
    ifstream infile;
    
    infile.open("myfile.txt");

    if(infile.is_open()){
        cout<<"File opened successfully"<<endl;
        infile>>c1>>c2>>c3;
        cout<<"Content of file is: "<<c1<<c2<<c3<<endl;
    }
    else{
        cout<<"Error in opening file"<<endl;
    }


    
    return 0;
}