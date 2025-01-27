#include <iostream>
#include <ctime>
using namespace std;

int main() {
    int p1 = 5, p2 = 5; // Initial rounds for both players

    cout << "Dice game:" << endl;

    bool win1 = false, win2 = false;
    int s1, s2;
    int sc1 = 0, sc2 = 0; // Initialize scores

    srand(time(0)); // Seed for randomness (called only once)

    // Play exactly 5 rounds
    for (int round = 1; round <= 5; ++round) {
        cout << "\nRound " << round << ":" << endl;

        s1 = (rand() % 6) + 1;  // Player 1 rolls
        s2 = (rand() % 6) + 1;  // Player 2 rolls
        cout << "Player 1 rolled: " << s1 << " | Player 2 rolled: " << s2 << endl;

        if (s1 > s2) {
            p1--;    // Player 1 wins this round
            sc1++;   // Increase Player 1's score
        } 
        else if (s2 > s1) {
            p2--;    // Player 2 wins this round
            sc2++;   // Increase Player 2's score
        }

        // If any player runs out of rounds, game ends
        if (p1 == 0 || p2 == 0) {
            break;  // Exit the loop if either player reaches 0 rounds
        }
    }

    // Output the results after 5 rounds
    cout << "\nFinal Scores:" << endl;
    cout << "Player 1: " << sc1 << " points" << endl;
    cout << "Player 2: " << sc2 << " points" << endl;

    // Declare the winner based on the score
    if (sc1 > sc2) {
        cout << "Player 1 won the game!" << endl;
    } else if (sc2 > sc1) {
        cout << "Player 2 won the game!" << endl;
    } else {
        cout << "The game is a tie!" << endl;
    }

    return 0;
}
