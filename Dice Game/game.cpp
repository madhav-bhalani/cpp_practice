#include <iostream>
#include<time.h>
using namespace std;

class Dice{
    private:
        int sides;
    
    public:
        Dice();
        int roll();
};

class Player{
    private:
        int score;

    public:
        Player();
        void addScore(int points);
        int getScore(){
            return score;
        };
         bool isComputer();

};

class Game{
    public:
        void playRound();
        void startGame();
       
};

int main()
{
    
    return 0;
}




