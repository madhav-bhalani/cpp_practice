#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
class Bank{
    private:
        int accnum;
        string name;
        int ammount;
    public:
        void openAccount(){
            cout << "1";
        }
        void balanceInquiry(){
            cout << "2";
        }
        void deposit(){
            cout << "3";
        }
        void withdrawal(){
            cout << "4";
        }
        void closeAccount(){
            cout << "5";
        }
        void showAllAccounts(){
            cout << "6";
        }
};
int main()
{
    Bank b;
    int x;
    do {
        cout << "Welcome to Theta Bank, How can I help you?" << endl;
        cout << "Select Desired Functionality from Below --->" << endl;
        cout << " 1. Open a new Account" << endl;
        cout << " 2. Balance Inquiry" << endl;
        cout << " 3. Deposit" << endl;
        cout << " 4. Withdrawal" << endl;
        cout << " 5. Close an Account" << endl;
        cout << " 6. Show All Account" << endl;
        cout << " 7. Quit" << endl;
        cin >> x;
        switch (x) {
            case 1: b.openAccount(); break;
            case 2: b.balanceInquiry(); break;
            case 3: b.deposit(); break;
            case 4: b.withdrawal(); break;
            case 5: b.closeAccount(); break;
            case 6: b.showAllAccounts(); break;
            case 7: cout << "Thank you for using Theta Bank. Goodbye!" << endl; break;
            default: cout << "Invalid choice. Please try again." << endl;
        }
    } while (x != 7);
    return 0;
}











