#include "User.h"


string User:: getUsername(){return username;}
int User:: getUserId(){return userId;}
string User:: getPhone(){return phone;}
string User:: getEmail(){return email;}
string User:: getFname(){return firstName;}
string User:: getLname(){return lastName;}


int User::nextUserId = 0;

User::User(string fname, string lname, string uname, string pass, string ph, string mail){
    nextUserId++;
    userId = nextUserId;
    firstName = fname;
    lastName = lname;
    username = uname;
    password = pass;
    phone = ph;
    email = mail;
}

void User::setNextUserId(int userId){
    nextUserId = userId;
}

int User::getNextUserId(){
    return nextUserId;
}

bool User::verifyPass(string pass){
    if(password == pass){
        return true;
    }
    else{
        return false;
    }
}

bool User::verifyUser(string uname){
    if(username == uname){
        return true;
    }
    else{
        return false;
    }
}

bool User::verifyPhone(string ph) {
    if (ph.length() != PHONE_LEN || !all_of(ph.begin(), ph.end(), ::isdigit)) {
        cout << "Invalid phone number" << endl;
        return false;
    }

    return true;
}


void User::updatePass(string newPass){
        password = newPass;
}


void User::updatePhone(string newPhone){
    phone = newPhone;
}

void User::updateEmail(string newEmail){
     email = newEmail;
}

//Serialization and operator overloading
ofstream & operator<<(ofstream &ofs, User &u){
    ofs<<u.userId<<endl;
    ofs<<u.firstName<<endl;
    ofs<<u.lastName<<endl;
    ofs<<u.username<<endl;
    ofs<<u.password<<endl;
    ofs<<u.phone<<endl;
    ofs<<u.email<<endl;
    return ofs;
}

ifstream & operator>>(ifstream &ifs, User &u){
    ifs>>u.userId;
    ifs>>u.firstName;
    ifs>>u.lastName;
    ifs>>u.username;
    ifs>>u.password;
    ifs>>u.phone;
    ifs>>u.email;
    return ifs;
}

ostream & operator<<(ostream &os, User &u){
    // os<<"Username: "<<u.getUsername()<<endl;
    os<<"User id: "<<u.getUserId()<<endl;
    os<<"First Name: "<<u.getFname()<<endl;
    os<<"Last Name: "<<u.getLname()<<endl;
    os<<"Phone Number: "<<u.getPhone()<<endl;
    os<<"Email: "<<u.getEmail()<<endl;
    return os;
}

