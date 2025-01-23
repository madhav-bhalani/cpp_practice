#include "UserManagement.h"
#include "User.h"
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