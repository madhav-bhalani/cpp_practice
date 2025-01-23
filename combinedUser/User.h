#ifndef USER_H
#define USER_H

#include<string>
#include<algorithm>
#include<map>
#include<fstream>
#include<vector>
#include<cstdlib>
#include <iostream>
using namespace std;


#define MIN_PASS 8
#define PHONE_LEN 10

class User{
    private:
        int userId;
        static int nextUserId;
        string firstName, lastName, username, password, phone, email, role;

    public:
        User(){};
        User(string fname, string lname, string uname, string pass, string ph, string mail);
        string getUsername();
        int getUserId();
        string getPhone();
        string getEmail();
        string getFname();
        string getLname();

        bool verifyPass(string pass);
        bool verifyPhone(string ph);
        void updatePass(string newPass);
        void updateEmail(string newEmail);
        void updatePhone(string newPhone);
        static void setNextUserId(int userId);
        static int getNextUserId();

        friend ofstream & operator<<(ofstream &ofs, User &u);
        friend ifstream & operator>>(ifstream &ifs, User &u);
        friend ostream & operator<<(ostream &os, User &u);
};


#endif