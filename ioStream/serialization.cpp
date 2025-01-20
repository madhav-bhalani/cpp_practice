#include<fstream>
#include<cstring>
#include <iostream>
using namespace std;

class Student{
    public:
        string name;
        int roll;
        string branch;

        friend ofstream & operator<<(ofstream &ofs, Student &s);

        friend ifstream & operator>>(ifstream &ifs, Student &s);
};

ofstream & operator<<(ofstream &ofs, Student &s){
    ofs<<s.name<<endl;
    ofs<<s.roll<<endl;
    ofs<<s.branch<<endl;
    return ofs;
}

ifstream & operator>>(ifstream &ifs, Student &s){
    ifs>>s.name>>s.roll>>s.branch;
    return ifs;
}


int main()
{
    string n, b;
    int r;
    cout<<"Enter name of student: "<<endl;
    getline(cin, n);
    cout<<"Enter roll no: "<<endl;
    cin>>r;
    cout<<"Enter branch: "<<endl;
    cin.ignore();
    getline(cin,b);

    Student s1;
    s1.name = n;
    s1.roll = r;
    s1.branch = b;

    ofstream ofs("student.txt", ios::trunc);

    ofs<<s1;
    ofs.close();

    //readind content from the file
    ifstream ifs;
    ifs.open("student.txt");

    if(ifs.is_open()){
        cout<<"File opened successfully"<<endl;
        ifs>>s1;
        cout<<"Contents of file are as follows:"<<endl;
        cout<<s1.name<<endl<<s1.roll<<endl<<s1.branch<<endl;
    }
    else{
        cout<<"File does not exist. ERROR!!"<<endl;
    }


    return 0;
}