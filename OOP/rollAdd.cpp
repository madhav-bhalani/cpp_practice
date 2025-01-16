#include <iostream>
using namespace std;

class Student{
    public: 
        int rollno;
        string name;
        static int addNum;

        Student(string n){
            name = n;
            addNum++;
            rollno = addNum;
        }

        void display(){
            cout<<"Name: "<<name<<" Roll No: "<<rollno<<endl;
        }
};

int Student::addNum = 0;

int main()
{
    Student s1("madhav");
    Student s2("harsh");
    Student s3("khevna");

    s1.display();
    s2.display();
    s3.display();


    return 0;
}