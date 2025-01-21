#include<string>
#include<map>
#include<fstream>
#include<vector>
#include<cstdlib>
#include <iostream>
using namespace std;

#define MIN_PASS 8
#define PHONE_LEN 10

class IncorrectPassword: public exception{};


class User{
    private:
        string username, password, phone, email;

    public:
        User(){};
        User(string uname, string pass, string ph, string mail);
        string getUsername(){return username;}
        string getPhone(){return phone;}
        string getEmail(){return email;}
       


        bool verifyPass(string pass);
        void updatePass(string newPass);
        void updateEmail(string newEmail);
        void updatePhone(string newPhone);

        friend ofstream & operator<<(ofstream &ofs, User &u);
        friend ifstream & operator>>(ifstream &ifs, User &u);
        friend ostream & operator<<(ostream &os, User &u);
};

class UserManagement{
    public:
        map<string, User> users;

    public:
        UserManagement();
        ~UserManagement();

        bool addUser(string uname, string pass, string ph, string mail);
        bool removeUser(string uname);
        User* loginUser(string uname, string pass);
        void displayAllUsers();
        User viewUserInfo(string uname);       
        bool updateEmail(string uname, string newMail);
};

int main()
{
    
    UserManagement userMan;
    User user;

    int c;
    string uname, pass, ph, mail, newPass, newMail, newPhone;

    cout<<"***User Management System***"<<endl;

    do{
        cout<<"\n\tSelect options from below: ";
        cout<<"\n\t1. Add new user";
        cout<<"\n\t2. Login";
        cout<<"\n\t3. Update Email";
        cout<<"\n\t4. Update Phone";
        cout<<"\n\t5. Update Password";
        cout<<"\n\t6. View User Info";
        cout<<"\n\t7. Remove User";
        cout<<"\n\t8. Display All Users";
        cout<<"\n\t9. Exit";

        cout<<"\nEnter your choice: ";
        cin>>c;

        switch (c)
        {
        case 1:
            cout<<"Enter Username: ";
            cin>>uname;
            do{
                cout<<"Enter Password: ";
                cin>>pass;

                if(pass.length() < MIN_PASS){
                    cout<<"Enter password with minimum "<<MIN_PASS<<" characters.";
                }
                else{
                    break;
                }
            }while(true);

            cout<<"Enter Phone Number: ";
            cin>>ph;
            cout<<"Enter Email: ";
            cin>>mail;

            bool success = userMan.addUser(uname, pass, ph, mail);
            if(success){
                cout<<"User "<<uname<<" added successfully";
            }   
            cout<<"User"<<uname<<" could'nt be added";
            break;

        case 2:
            cout<<"Enter username: ";
            cin>>uname;
            cout<<"Enter password: ";
            cin>>pass;

            User *u = userMan.loginUser(uname, pass);
            cout<<*u;
            break;

        case 3:
            cout<<"E"
        default:
            break;
        }
    }

    return 0;
}


User::User(string uname, string pass, string ph, string mail){
    username = uname;
    password = pass;
    phone = ph;
    email = mail;
}

bool User::verifyPass(string pass){
    if(password == pass){
        return true;
    }
    else{
        return false;
    }
}

void User::updatePass(string newPass){
    if(password != newPass){
        password = newPass;
    }
}

bool UserManagement::updateEmail(string uname, string newMail){
    map<string, User>::iterator itr = users.find(uname);

    if(itr != users.end() && itr->second.getEmail() != newMail){
        itr->second.updateEmail(newMail);
        return true;
    }    
    else if(itr == users.end()){
        cout<<"User "<<uname<<" does not exist!!";
    }
    else{
        cout<<"New email is same as current email!!";
    }

    return false;
}

void User::updatePhone(string newPhone){
    if(phone != newPhone){
        phone = newPhone;
    }
}

void User::updateEmail(string newEmail){
     email = newEmail;
}


ofstream & operator<<(ofstream &ofs, User &u){
    ofs<<u.username<<endl;
    ofs<<u.password<<endl;
    ofs<<u.phone<<endl;
    ofs<<u.email<<endl;
    return ofs;
}

ifstream & operator>>(ifstream &ifs, User &u){
    ifs>>u.username;
    ifs>>u.password;
    ifs>>u.phone;
    ifs>>u.email;
    return ifs;
}

ostream & operator<<(ostream &os, User &u){
    os<<"Username: "<<u.getUsername()<<endl;
    os<<"Phone Number: "<<u.getPhone()<<endl;
    os<<"Email: "<<u.getEmail()<<endl;
    return os;
}


//declarations of the UserManagement class

UserManagement::UserManagement(){
    User user;
    ifstream ifs;

    ifs.open("Users.data");

    if(!ifs){
        cout<<"Error!! file not found"<<endl;
        return;
    }

    while(!ifs.eof()){
        ifs>>user;
        users.insert(pair<string, User>(user.getUsername(), user));
    }
    ifs.close();
}

bool UserManagement::addUser(string uname, string pass, string ph, string mail){
    ofstream ofs("User.data", ios::trunc);
    User user(uname, pass, ph, mail);
    
    users.insert(pair<string, User>(user.getUsername(), user));
    
    map<string, User>::iterator itr;
    for(itr = users.begin();itr != users.end();itr++){
        ofs<<itr->second;
    }

    if(ofs){
        return true;
        ofs.close();
    }
    else{
        return false;
    }
}

bool UserManagement::removeUser(string uname){
    map<string, User>::iterator itr = users.find(uname);
    
    if(itr == users.end()){
        cout<<"User "<<uname<<" not found!!"<<endl;
        return false;
    }
   size_t  remCount = users.erase(uname);
   if(remCount > 0){
    cout<<"User "<<uname<<" removed!!"<<endl;
    return true;
   }
   cout<<"User "<<uname<<" could not be removed!!"<<endl;
   return false;
}

User* UserManagement::loginUser(string uname, string pass){
    map<string, User>::iterator itr = users.find(uname);

    if(itr != users.end() && itr->second.verifyPass(pass))
    {
        cout<<"User "<<uname<<" logged in successfully";
        return &(itr->second);
    }

    return nullptr;
}

void UserManagement::displayAllUsers(){
    map<string, User>::iterator itr;
    for(itr=users.begin();itr!=users.end();itr++){
        cout<<"Users: "<<endl<<itr->first<<endl<<itr->second<<endl;
    }
}

User UserManagement::viewUserInfo(string uname){
    map<string, User>::iterator itr = users.find(uname);
    return itr->second;
}

UserManagement::~UserManagement(){
    ofstream ofs("Users.data", ios::trunc);
    
    map<string, User>::iterator itr;
    for(itr=users.begin();itr!=users.end();itr++){
        ofs<<itr->second;
    }

    ofs.close();
}