#include<fstream>
#include<vector>
#include<cstring>
#include<map>
#include<cstdlib>
#include <iostream>
using namespace std;

#define MIN_BAL 500

class InsufficientFunds: public exception{};

class Account{
    private:
        long accNumber;
        string firstName;
        string lastName;
        float balance;  
        static long nextAccNumber;

    public:
        Account(){};
        Account(string fname, string lname, float bal);
        long getAccNumber(){return accNumber;}
        float getBalance(){return balance;}
        string getFirstName(){return firstName;}
        string getLastName(){return lastName;}

        void Deposit(float amount);
        void Withdraw(float amount);
        static void setLastAccNumber(long accNumber);
        static long getLastAccNumber();

        friend ofstream & operator<<(ofstream &ofs, Account &acc);
        friend ifstream & operator>>(ifstream &ifs, Account &acc);
        friend ostream & operator<<(ostream &os, Account &acc);


};

long Account::nextAccNumber = 0;

class Bank{

    private:
        map<long, Account> accounts;
    public:
        Bank();
        
        Account OpenAcc(string fname, string lname, float balance);
        Account BalEnquiry(long accNumber);
        Account Withdraw(long accNumber, float amount);
        Account Deposit(long accNumber, float amount);
        
        void closeAcc(long accNumber);
        void viewAllAcc();

        ~Bank();
};

int main()
{
    Bank b;
    Account acc;

    int choice;
    long accNum;
    string fname, lname;
    float bal, amt;

    cout<<"***Banking System***";
    do{
        cout<<"\n\tSelect one option below ";
        cout<<"\n\t1 Open an Account";
        cout<<"\n\t2 Balance Enquiry";
        cout<<"\n\t3 Deposit";
        cout<<"\n\t4 Withdrawal";
        cout<<"\n\t5 Close an Account";
        cout<<"\n\t6 Show All Accounts";
        cout<<"\n\t7 Quit";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter First Name: ";
                cin>>fname;
                cout<<"Enter Last Name: ";
                cin>>lname;
                cout<<"Enter initial balance: ";
                cin>>bal;
                acc=b.OpenAcc(fname, lname, bal);
                cout<<"Congratulations account created!!"<<endl;
                cout<<acc;
                break;

            case 2:
                cout<<"Enter Account Number: ";
                cin>>accNum;
                acc=b.BalEnquiry(accNum);
                cout<<acc;
                break;

            case 3:
                cout<<"Enter Account Number: ";
                cin>>accNum;
                cout<<"Enter amount to be deposited: ";
                cin>>amt;
                acc=b.Deposit(accNum, amt);
                cout<<acc;
                break;

            case 4:
                cout<<"Enter Account Number: ";
                cin>>accNum;
                cout<<"Enter amount to be withdrawn: ";
                cin>>amt;
                acc=b.Withdraw(accNum, amt);
                cout<<acc;
                break;

            case 5:
                cout<<"Enter Account Number: ";
                cin>>accNum;
                b.closeAcc(accNum);
                cout<<"Account is closed!!"<<endl;
                cout<<acc;
                break;

            case 6:
                b.viewAllAcc();
                break;
            
            case 7:
                break;
            
            default:
                cout<<"\nEnter valid input"<<endl;
                exit(0);
        }
        

    }
    while(choice!=7);

    return 0;
}

Account::Account(string fname, string lname, float balance){
    nextAccNumber++;
    accNumber = nextAccNumber; 
    firstName = fname;
    lastName = lname;
    this->balance = balance;
}

void Account::setLastAccNumber(long accNumber){
    nextAccNumber = accNumber;
}

void Account::Deposit(float amount){
    balance += amount;
}

void  Account::Withdraw(float amount){
    if(balance <= MIN_BAL){
        throw InsufficientFunds();
    }
    else{
         balance -= amount;
    }
}

long Account::getLastAccNumber(){
    return nextAccNumber;
}

ofstream & operator<<(ofstream &ofs, Account &acc){
    ofs<<acc.accNumber<<endl;
    ofs<<acc.firstName<<endl;
    ofs<<acc.lastName<<endl;
    ofs<<acc.balance<<endl;

    return ofs;
}

ifstream & operator>>(ifstream &ifs, Account &acc){
    ifs>>acc.accNumber;
    ifs>>acc.firstName;
    ifs>>acc.lastName;
    ifs>>acc.balance;
    return ifs;
}

ostream & operator<<(ostream &os, Account &acc){
    os<<"Account Number: "<<acc.getAccNumber()<<endl;
    os<<"First Name: "<<acc.getFirstName()<<endl;
    os<<"Last Name: "<<acc.getLastName()<<endl;
    os<<"Balance: "<<acc.getBalance()<<endl;
    return os;    
 }

 Bank::Bank(){
    Account account;

    ifstream ifs;

    ifs.open("Bank.data");
    if(!ifs){
        //cout<<"Error in Opening! File Not Found!!"<<endl;
        return;
    }
    while(!ifs.eof()){
        ifs>>account;
        accounts.insert(pair<long, Account>(account.getAccNumber(), account));
    }
    Account::setLastAccNumber(account.getAccNumber());
    ifs.close();
 }

 Account Bank::OpenAcc(string fname, string lname, float balance){
    ofstream ofs("Bank.data", ios::trunc);
    Account account(fname,lname,balance);

    accounts.insert(pair<long, Account>(account.getAccNumber(), account));
    map<long,Account>::iterator itr;
    for(itr=accounts.begin();itr!=accounts.end();itr++){
        ofs<<itr->second;
    }

    ofs.close();
    return account;

 }

 Account Bank::BalEnquiry(long accNumber){
    map<long, Account>::iterator itr = accounts.find(accNumber);
    return itr->second;
}

Account Bank::Deposit(long accNumber, float amount){
    map<long, Account>::iterator itr = accounts.find(accNumber);
    itr->second.Deposit(amount);
    return itr->second;
}

Account Bank::Withdraw(long accNumber, float amount){
    map<long, Account>::iterator itr = accounts.find(accNumber);
    itr->second.Withdraw(amount);
    return itr->second;
}
void Bank::closeAcc(long accNumber){
    map<long, Account>::iterator itr  = accounts.find(accNumber);
    cout<<"Account deleted!!"<<itr->second;
    accounts.erase(accNumber);
}

void Bank::viewAllAcc(){
    map<long, Account>::iterator itr;
    for(itr=accounts.begin();itr!=accounts.end();itr++){
        cout<<"Account "<<itr->first<<endl<<itr->second<<endl;
    }
}

Bank::~Bank(){
    ofstream ofs("Bank.data", ios::trunc);

    map<long, Account>::iterator itr;
    for(itr=accounts.begin();itr!=accounts.end();itr++){
        ofs<<itr->second;
    }
    ofs.close();

}