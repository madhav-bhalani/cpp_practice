
#include<iostream>
#include "UserManagement.h"
#include "User.h"
#include "User.cpp"
#include "UserManagement.cpp"

int main()
{
    
    UserManagement userMan;
    User user;

    int c1, c2, role;
    string fname, lname, uname, pass, ph, mail, newPass, newMail, newPhone;

    cout<<"***User Management System***"<<endl;

    cout<<"Please select your role: ";
    cout<<"\n\t1. Admin \n\t2.User";
    cin>>role;

    do{
        switch(role){
            case 1:
            {

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
                    cin>>c1;

                    switch (c1)
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
                   try {
                                    User user = userMan.viewUserInfo(uname);
                                    cout << user; 
                                } 
                            catch (const runtime_error& e) {
                                    cout << e.what() << endl; 
                            }   
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
                    exit(0);
                }
                default:
                {
                    cout<<"\nEnter valid input"<<endl;
                    exit(0);
                }
            }
    
}
                while(c1!=9);

            }

            case 2:
            {
                do{
                    cout<<"\n\tSelect options from below: ";
                    cout<<"\n\t1. Login";
                    cout<<"\n\t2. Update Email";
                    cout<<"\n\t3. Update Phone";
                    cout<<"\n\t4. Update Password";
                    cout<<"\n\t5. View Your Profile";
                    cout<<"\n\t6. Exit";

                    cout<<"\nEnter your choice: ";
                    cin>>c2;

                    switch(c2){
                        case 1:
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

                        case 2:
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
                        case 3:
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

                        case 4:
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

                        case 5:
                        {
                            cout<<"Enter username: ";
                            cin>>uname;
                            try {
                                    User user = userMan.viewUserInfo(uname);
                                    cout << user; 
                                } 
                            catch (const runtime_error& e) {
                                    cout << e.what() << endl; 
                            }   
                            break;

                        }
                        case 6:
                        {
                            exit(0);
                        }

                        default:
                        {
                            cout<<"\nInvalid input.";
                            exit(0);
                        }


                    }
                }while(c2!=6);
            }

            default:
                cout<<"\nInvalid input";
                exit(0);
        } 
    }while(role!=2);

    return 0;
}


