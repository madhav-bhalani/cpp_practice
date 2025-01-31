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
        vector<int> scores;
    
    public:
        
        Player(){};
        Player(string name, char role){
            nextUserId++;
            userId = nextUserId;
            username = name;
            userRole = role;
        }

        string getName(){
            return username;
        }

        int getPoints(){
            return points;
        }

        int getId(){
            return userId;
        }

        char getRole(){
            return userRole;
        }

        bool isComp(){
            if(userRole == 'C' || userRole == 'c'){
                return true;
            }
            else if(userRole == 'H' || userRole == 'h'){
                return false;
            }
        }
};

int Player::nextUserId = 0;

class Dice{
    int throwDice(){
        return (rand()%6)+1;
    }
};

class DiceGame{
    private:
        map<int, Player> players;
        Dice dice;
       
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

        void compPlay(){

            
        }

        void userPlay(){

        }

        void declareResult(){
            // also display scores of each player at end of that specific round
            // result after each round
        }

        void scoreBoard(){
            //display scoreboard at end of game
        }

};

int main()
{
    
    return 0;
}