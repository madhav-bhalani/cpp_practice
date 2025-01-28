#include <iostream>
#include <ctime>
using namespace std;

int main() {
    int p1 = 5, p2 = 5; 

    cout << "Dice game:" << endl;

    bool win1 = false, win2 = false;
    int s1, s2;
    int sc1 = 0, sc2 = 0; 

    
    srand(time(0)); 
    
    for (int round = 1; round <= 5; ++round) {
        cout << "\nRound " << round << ":" << endl;

        s1 = (rand() % 6) + 1;  
        s2 = (rand() % 6) + 1;  
        cout << "Player 1 rolled: " << s1 << " | Player 2 rolled: " << s2 << endl;

        if (s1 > s2) {
            p1--;    
            sc1++; 
        } 
        else if (s2 > s1) {
            p2--;    
            sc2++;   
        }
        else if(s1==s2){
            cout<<"Round "<<round<<" tied.";
        }

        if (p1 == 0 || p2 == 0) {
            break;  
        }
    }

    
    cout << "\nFinal Scores:" << endl;
    cout << "Player 1: " << sc1 << " points" << endl;
    cout << "Player 2: " << sc2 << " points" << endl;

    
    if (sc1 > sc2) {
        cout << "Player 1 won the game!" << endl;
    } else if (sc2 > sc1) {
        cout << "Player 2 won the game!" << endl;
    } else {
        cout << "The game is a tie!" << endl;
    }

    return 0;
}
