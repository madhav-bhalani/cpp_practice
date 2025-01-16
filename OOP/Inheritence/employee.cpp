#include<cstring>
#include <iostream>
using namespace std;

class Employee{
    private:
        int eid;
        string name;

    public:
        Employee(int e, string n){
            eid = e;
            name = n;
        }

        int getEid(){return eid;}
        string getName(){return name;}
};

class fullTimeEmployee: public Employee{
    private: 
        int salary;
    
    public:
        fullTimeEmployee(int e, string n, int sal): Employee(e,n){
            salary = sal;
        }

        int getSalary(){
            return salary;
        }
};

class partTimeEmployee: public Employee{
    private:
        int wage;

    public: 
        partTimeEmployee(int e, string n, int w): Employee(e, n){
            wage = w;
        }

        int getWage(){
            return wage;
        }
};

int main()
{
    fullTimeEmployee f(12, "madhav", 500000);
    partTimeEmployee p(43, "harsh", 7000);

    cout<<"Employee id: "<<f.getEid()<<" named "<<f.getName()<<" works for "<<f.getSalary()<<" per month."<<endl;
    cout<<"Employee id: "<<p.getEid()<<" named "<<p.getName()<<" works for "<<p.getWage()<<" per day."<<endl;


    return 0;
}