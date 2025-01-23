#ifndef USERMANAGEMENT_H
#define USERMANAGEMENT_H

#include <map>
#include "User.h"

class UserManagement{
    public:
        map<string, User> users;

    public:
        UserManagement();
        ~UserManagement();

        bool addUser(string fname, string lname, string uname, string pass, string ph, string mail);
        bool removeUser(string uname);
        bool loginUser(string uname, string pass);
        void displayAllUsers();
        User viewUserInfo(string uname);       
        bool updateEmail(string uname, string newMail);
        bool updatePhone(string uname, string newPhone);
        bool updatePass(string uname, string newPass);
        void saveToFile();
};

#endif