#include <iostream>
using namespace std;

class Player{
    private:
        int points = 0;

    public:

        int getPoints(){
            return points;
        }

        void increasePoints(){
            points++;
        }

        // void decreasePoints(){
        //     points--;
        // }
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


            int playRoll = dice.throwDice();
            cout<<"You rolled: "<<playRoll<<endl;

            int compRoll = dice.throwDice();
            cout<<"Computer rolled: "<<compRoll<<endl;
            

            if(playRoll > compRoll){
                cout<<"You win this round!!"<<endl;
                player.increasePoints();
            }
            else if(compRoll > playRoll){
                cout<<"Computer wins this round!!"<<endl;
        
                comp.increasePoints();
            }
            else{
                cout<<"This round tied!!"<<endl;
            }

            cout<<"Your points: "<<player.getPoints()<<" || "<<"Computer points: "<<comp.getPoints()<<endl;

       }

    //    bool isGameOver(){
    //     return player.getPoints() == 0 || comp.getPoints() == 0;
    //    }

       void winner(){
        if(player.getPoints() > comp.getPoints()){
            cout<<"Congratulations..You won the game!!"<<endl;
        }
        else if(comp.getPoints() > player.getPoints()){
            cout<<"Computer wins the game!!"<<endl;
        }
        else{
            cout<<"Game tied!!"<<endl;
        }
       }
};

int main()
{   
    srand(time(0));
    
    DiceGame game;

    int round;
    int ip;

    cout<<".... Welcome to the dice game ...."<<endl;
    
    cout<<"Enter the number of rounds to be played:"<<endl;
    cin>>round;

    for(int i = 1; i<=round; i++){
        cout<<"Press 1 to roll the dice."<<endl;
        cin>>ip;

        if(ip == 1){
            cout<<"Round "<<i<<endl;
            game.play();
        }
        else{
            cout<<"Invalid input!!"<<endl;
        }
    }

    game.winner();
    
    return 0;
} 