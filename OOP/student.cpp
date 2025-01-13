#include <iostream>
#include<cstring>
using namespace std;

class Student{
    private:
        int rollNum;
        string name;
        int phy, chem, math;
        float avg;
        char g;

    public:
        Student(int r, string n, int p, int c, int m){
            rollNum = r;
            name = n;
            phy = p;
            chem = c;
            math = m;
        }

        char grade(int p, int c, int m){
            avg = float( (p+c+m) / 3); 
            if(avg >= 80.0 ){
                g = 'A';
            }
            else if(avg >=65 && avg < 80){
                g = 'B';
            }
            else if(avg >= 35 && avg < 65){
                g = 'C';
            }
            else if(avg < 35){
                g = 'F';
            }
            return g;
            
        }
};

int main()
{  
    int roll, m1, m2, m3;
    string nam;

    cout<<"Enter your roll number:"<<endl;
    cin>>roll;
    cin.ignore();
    cout<<"Enter your name:"<<endl;
    getline(cin,nam);
    cout<<"Enter marks of physics:"<<endl;
    cin>>m1;
    cout<<"Enter marks of chemistry:"<<endl;
    cin>>m2;
    cout<<"Enter marks of maths:"<<endl;
    cin>>m3;

    Student stu(roll, nam, m1, m2, m3);

    cout<<nam<<"'s"<<" grade is "<<stu.grade(m1, m2, m3)<<"."<<endl;

    return 0;
}