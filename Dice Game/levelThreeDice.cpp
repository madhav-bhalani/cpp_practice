#include <iostream>
#include<cstring>
#include<algorithm>
#include <bits/stdc++.h>
using namespace std;

class Player{
    private:
        int userId;
        string username;
        int points = 0;
        static int nextUserId;
        char userRole;

    public:
        
        Player(){};
        Player(string name, char role){
            nextUserId++;
            userId = nextUserId;
            username = name;
            userRole = role;
        }

        string getName() const{
            return username;
        }

        int getPoints() const{
            return points;
        }

        int getId() const{
            return userId;
        }

        char getRole() const{
            return userRole;
        }

        bool isComp() const{ 
            return userRole == 'C' || userRole == 'c';
        }

        void addPoints(int p) {
            points += p;
        }


        friend ostream &operator<<(ostream &os, Player &p);
};

ostream &operator<<(ostream &os, Player &p){
    os<<"Player Name: "<<p.username<<endl;
    os<<"Player Role: "<<p.userRole<<endl;
    os<<"Player Points: "<<p.points<<endl;
    return os;
}


int Player::nextUserId = 0;

class Dice{
    public:
        int throwDice(){
            return (rand()%6)+1;
        }
};

class DiceGame{
    private:
        map<int, Player> players;
        Dice dice;
        vector<int> scores;


    public:
        void addPlayer(string n, char r){
            Player player(n, r);

            auto result = players.insert(pair<int, Player>(player.getId(), player));

            if(result.second){
                cout<<"Player added!!"<<endl;
            }
            else{
                cout<<"Error in adding player!!"<<endl;
            }
        
        }

        void compPlay(Player &player){
            int roll = dice.throwDice();
            cout<<player.getName()<<"(Computer) rolled: "<<roll<<endl;
            player.addPoints(roll);
        }

        void userPlay(Player &player){
            int userInput;
            cout << player.getName() << ", press 1 to roll the dice: ";
            cin >> userInput;
            if (userInput == 1) {
                int roll = dice.throwDice();
                cout << player.getName() << " rolled: " << roll << endl;
                player.addPoints(roll);
            } else {
                cout << "Invalid input! Skipping turn." << endl;
            }
        }

        void playRound() {
            scores.clear(); 
            for (auto &entry : players) {
                Player &player = entry.second;
                if (player.isComp()) {
                    compPlay(player);
                } else {
                    userPlay(player);
                }
                scores.push_back(player.getPoints()); 
            }
        }

         void declareResult() {
            if (scores.empty()) return;

            int maxScore = *max_element(scores.begin(), scores.end());
            Player *winner = nullptr;

            for (auto &entry : players) {
                Player &player = entry.second;
                if (player.getPoints() == maxScore) {
                    winner = &player;
                    break;
                }
            }

            if (winner) {
                cout << "\n--- GAME OVER ---" << endl;
                cout << "Winner: " << winner->getName() << " with " << winner->getPoints() << " points" << endl;
            }
        }

        void scoreBoard() {
            vector<pair<int, Player>> sortedPlayers(players.begin(), players.end());
            sort(sortedPlayers.begin(), sortedPlayers.end(), [](const pair<int, Player> &a, const pair<int, Player> &b) {
                return a.second.getPoints() > b.second.getPoints();
            });

            cout << "\n--- SCOREBOARD ---" << endl;
            cout << "Rank\tName\t\tPoints" << endl;
            int rank = 1;
            for (const auto &entry : sortedPlayers) {
                cout << rank << "\t" << entry.second.getName() << "\t\t" << entry.second.getPoints() << endl;
                rank++;
            }
        }

        const map<int, Player>& getPlayers() const {
            return players;
        }

};

int main()
{
    srand(time(0)); 

    DiceGame game;
    int rounds, numPlayer;
    string name;
    char role;

    cout << "Enter the number of rounds: ";
    cin >> rounds;
    cout << "Enter the number of players: ";
    cin >> numPlayer;

    for (int i = 0; i < numPlayer; ++i) {
        cout << "Enter player " << i + 1 << " name: ";
        cin >> name;
        cout << "Enter player " << i + 1 << " role (C for Computer, H for Human): ";
        cin >> role;
        game.addPlayer(name, role);
    }

     for (int r = 1; r <= rounds; ++r) {
        cout << "\n--- Round " << r << " ---" << endl;
        game.playRound();

        cout << "\n--- Round " << r << " Results ---" << endl;
        for (auto &entry : game.getPlayers()) { 
            const Player &player = entry.second;
            cout << player.getName() << " scored: " << player.getPoints() << " points" << endl;
        }
    }


    game.declareResult();
    game.scoreBoard();

    return 0;
    
    return 0;
}
