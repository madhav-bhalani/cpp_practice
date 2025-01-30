#include <iostream>
using namespace std;

class Player{
    private:
        int points = 5;

    public:

        int getPoints(){
            return points;
        }

        void increasePoints(){
            points++;
        }

        void decreasePoints(){
            points--;
        }
};

class Dice{
    public:
        int throwDice(){
           return (rand()%6)+1; 
        }
};

class DiceGame{
    private:
        Player player;
        Player comp;
        Dice dice;

    public:
       void play(){

            int compPoint = comp.getPoints();
            int playPoint = player.getPoints();

            int compRoll = dice.throwDice();
            int playRoll = dice.throwDice();

            cout<<"Computer rolled: "<<compRoll<<endl;
            cout<<"You rolled: "<<playRoll<<endl;

            if(playRoll > compRoll){
                cout<<"You win this round!!"<<endl;
                comp.increasePoints();
                player.decreasePoints();
            }
            else if(compRoll > playRoll){
                cout<<"Computer wins this round!!"<<endl;
                comp.decreasePoints();
                player.increasePoints();
            }
            else{
                cout<<"This round tied!!"<<endl;
            }

            cout<<"Your points: "<<player.getPoints()<<" || "<<"Computer points: "<<comp.getPoints()<<endl;

       }

       bool isGameOver(){
        return player.getPoints() == 0 || comp.getPoints() == 0;
       }

       void winner(){
        if(player.getPoints() == 0){
            cout<<"Congratulations..You won the game!!"<<endl;
        }
        else if(comp.getPoints() == 0){
            cout<<"Computer wins the game!!"<<endl;
        }
       }
};

int main()
{   
    srand(time(0));
    
    DiceGame game;

    int ip;
    cout<<".... Welcome to the dice game ...."<<endl;
    
    while(!game.isGameOver()){
        cout<<"Press 1 to roll the dice."<<endl;
        cin>>ip;

        if(ip == 1){
            game.play();
        }
        else{
            cout<<"Invalid input!!"<<endl;
        }
    }

    game.winner();
    



    return 0;
}