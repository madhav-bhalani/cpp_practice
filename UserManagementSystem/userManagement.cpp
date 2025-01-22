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
        int userId;
        static int nextUserId;
        string firstName, lastName, username, password, phone, email;

    public:
        User(){};
        User(string fname, string lname, string uname, string pass, string ph, string mail);
        string getUsername(){return username;}
        int getUserId(){return userId;}
        string getPhone(){return phone;}
        string getEmail(){return email;}
        string getFname(){return firstName;}
        string getLname(){return lastName;}

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

int User::nextUserId = 0;

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

int main()
{
    
    UserManagement userMan;
    User user;

    int c;
    string fname, lname, uname, pass, ph, mail, newPass, newMail, newPhone;

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
        {
            cout<<"Enter First Name: ";
            cin>>fname;
            cout<<"Enter Last Name: ";
            cin>>lname;
            cout<<"Enter Username: ";
            cin>>uname;
            do{
                cout<<"Enter Password: ";
                cin>>pass;

                if(pass.length() < MIN_PASS){
                    cout<<"Enter password with minimum "<<MIN_PASS<<" characters."<<endl;
                }
                else{
                    break;
                }
            }while(true);
            
            do{
                cout<<"Enter Phone Number: ";
                cin>>ph;
                
                
            }while(user.verifyPhone(ph) == false);
            
            cout<<"Enter Email: ";
            cin>>mail;

            bool s = userMan.addUser(fname, lname, uname, pass, ph, mail);
            if(s){
                cout<<"User "<<uname<<" added successfully";
            }   
           else{
             cout<<"User"<<uname<<" could not  be added";
           }
            break;
        }
        case 2:
        {
            cout<<"Enter username: ";
            cin>>uname;
            cout<<"Enter password: ";
            cin>>pass;

            bool su = userMan.loginUser(uname, pass);
            if(su){
                cout<<"Welcome "<<uname<<" :)";
            }
            else{
                cout<<"Login failed!!";
            }
            break;
        }
        case 3:
        {
            cout<<"Enter your username: ";
            cin>>uname;
            cout<<"Enter the new e-mail here: ";
            cin>>newMail;
            bool suc = userMan.updateEmail(uname, newMail);
            if(suc){
                cout<<"E-mail updated successfully";
            }
            else{
                 cout<<"E-mail update failed!!";
            }
           
            break;
        }
        case 4:
        {
            cout<<"Enter yout username: ";
            cin>>uname;
            cout<<"Enter the new phone number here: ";
            cin>>newPhone;
            bool succ = userMan.updatePhone(uname, newPhone);
            if(succ){
                cout<<"Phone number updated successfully";
            }
            else{
                cout<<"Phone number update failed!!";
            }
            
            break;
        }
        case 5:
        {
            cout<<"Enter your username: ";
            cin>>uname;
            cout<<"Enter the new password here: ";
            cin>>newPass;
            bool succe = userMan.updatePass(uname, newPass);
            if(succe){
                cout<<"Password updated successgully";
            }
            else{
                 cout<<"Password update failed!!";
            }
           
            break;
        }
        case 6:
        {
            cout<<"Enter username: ";
            cin>>uname;
            user = userMan.viewUserInfo(uname);
            cout<<user;
            break;
        }
        case 7:
        {
            cout<<"Enter username: ";
            cin>>uname;
            userMan.removeUser(uname);
            break;
        }
        case 8:
        {
            userMan.displayAllUsers();
            break;
        }
        case 9:
        {
            break;
        }
        default:
        {
            cout<<"\nEnter valid input"<<endl;
            exit(0);
        }
    }
    
}
    while(c!=9);


    return 0;
}


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

bool User::verifyPhone(string ph) {
    if (ph.length() != PHONE_LEN) {
        cout << "Phone number must be of " << PHONE_LEN << " digits!!" << endl;
        return false;
    }

    for (char c : ph) {
        if (!isdigit(c)) {
            cout << "Phone number must only contain digits!" << endl;
            return false;
        }
    }

    return true;
}


//UPDATE PASSWORD
bool UserManagement::updatePass(string uname, string newPass){
    map<string, User>::iterator itr = users.find(uname);

    if(itr != users.end() && itr->second.verifyPass(newPass) == false){
        itr->second.updatePass(newPass);

        saveToFile();

        return true;
    }
    else if(itr == users.end()){
        cout<<"User "<<uname<<" does not exist!!";
    }
    else{
        cout<<"The new password is same as the current password";
    }
    return false;
}
void User::updatePass(string newPass){
        password = newPass;
}


//UPDATE EMAIL
bool UserManagement::updateEmail(string uname, string newMail){
    map<string, User>::iterator itr = users.find(uname);

    if(itr != users.end() && itr->second.getEmail() != newMail){
        itr->second.updateEmail(newMail);

        saveToFile();

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
void User::updateEmail(string newEmail){
     email = newEmail;
}


//UPDATE PHONE
bool UserManagement::updatePhone(string uname, string newPhone){
    map<string, User>::iterator itr = users.find(uname);

    if(itr!=users.end() && itr->second.getPhone()!=newPhone){
        itr->second.updatePhone(newPhone);

        saveToFile();

        return true;
    }
    else if(itr == users.end()){
        cout<<"User "<<uname<<" does not exist!!";
    }
    else{
        cout<<"New phone number is same as the current phone number!!";
    }

    return false;
}
void User::updatePhone(string newPhone){
    phone = newPhone;
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


//declarations of the UserManagement class

void  UserManagement::saveToFile(){
     ofstream ofs("Users.data", ios::trunc);
        for (auto &entry : users) {
            ofs << entry.second;
        }
        ofs.close();
}

UserManagement::UserManagement(){
    User user;
    ifstream ifs;

    ifs.open("Users.data");

    if(!ifs){
        cout<<"Error!! file not found"<<endl;
        return;
    }
    int maxUser = 0;
    while(ifs >> user){
        users.insert(pair<string, User>(user.getUsername(), user));
        if(user.getUserId()>maxUser){
            maxUser = user.getUserId();
        }
    }
    ifs.close();

    User::setNextUserId(maxUser);
}

bool UserManagement::addUser(string fname, string lname, string uname, string pass, string ph, string mail){
    ofstream ofs("Users.data", ios::trunc);
    User user(fname, lname, uname, pass, ph, mail);
    
    users.insert(pair<string, User>(user.getUsername(), user));
    
    map<string, User>::iterator itr;
    for(itr = users.begin();itr != users.end();itr++){
        ofs<<itr->second;
    }
 
    if(ofs){
       
        return true;
        
    }
    else{
         ofs.close();
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
    saveToFile();
    cout<<"User "<<uname<<" removed!!"<<endl;
    return true;
   }
   cout<<"User "<<uname<<" could not be removed!!"<<endl;
   return false;
}

bool UserManagement::loginUser(string uname, string pass){
    map<string, User>::iterator itr = users.find(uname);

    if(itr != users.end() && itr->second.verifyPass(pass)){
        cout<<"Logged in successfully";
        return true;
    }
    else if(itr == users.end()){
        cout<<"User "<<uname<<" does not exist!!";
    }
    else{
        cout<<"Please enter a valid username or password!!";
    }
    return false;
}

void UserManagement::displayAllUsers(){
    map<string, User>::iterator itr;
    cout<<"Users List: ";
    for(itr=users.begin();itr!=users.end();itr++){
        cout<<endl<<itr->first<<endl<<itr->second<<endl;
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