#include <iostream>
#include <ctime>
using namespace std;

int throwDice() {
    return (rand() % 6) + 1; // Generate a random number between 1 and 6
}

int main() {
    srand(time(0)); // Seed for randomness

    int playerPoints = 5, computerPoints = 5;
    int playerRoll, computerRoll;
    int userInput;

    cout << "Welcome to the Dice Game!" << endl;
    cout << "Press 1 to roll the dice. The game ends when a player reaches 0 points." << endl;

    while (playerPoints > 0 && computerPoints > 0) {
        cout << "\nPress 1 to roll the dice: ";
        cin >> userInput;

        if (userInput == 1) {
            // Rolling dice for both players
            playerRoll = throwDice();
            computerRoll = throwDice();

            cout << "You rolled: " << playerRoll << endl;
            cout << "Computer rolled: " << computerRoll << endl;

            // Determine the round winner using YOUR LOGIC
            if (playerRoll > computerRoll) {
                cout << "You win this round!" << endl;
                playerPoints--;   // Decrease player's points
                computerPoints++; // Increase computer's points
            }
            else if (computerRoll > playerRoll) {
                cout << "Computer wins this round!" << endl;
                computerPoints--; // Decrease computer's points
                playerPoints++;   // Increase player's points
            }
            else {
                cout << "It's a tie! No points changed." << endl;
            }

            // Display updated scores
            cout << "Your Points: " << playerPoints << " | Computer Points: " << computerPoints << endl;
        }
        else {
            cout << "Invalid input! Please enter 1 to roll the dice." << endl;
        }
    }

    // Declare Winner
    cout << "\n--- GAME OVER ---" << endl;
    if (playerPoints == 0) {
        cout << "Computer Wins the Game!" << endl;
    }
    else {
        cout << "You Win the Game!" << endl;
    }

    return 0;
}
