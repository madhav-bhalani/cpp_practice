#include <iostream>

#include<time.h>
using namespace std;

class DiceGame{
    private:
        int round;

    public:
        void setRound(int r){
            round = r;
        }

        int getRound(){
            return round;
        }


};

class Player:public DiceGame{
    private:
        int score;
        int initialPoints;
        

    public:
        Player(int s, int p){
            score = s;
            initialPoints = p;
        }

        void win(){
            initialPoints--;
            score++;
        }

        int getIP(){
            return initialPoints;
        }

        void lose(){
            initialPoints++;
            score++;
        }

        bool setComputer(){
            return true;
        }

        int getScore(){
            return score;
        }

        int r = getRound();



        int throwDice(){ 
            return (rand()%6)+1;

        }

        void play(int x, int y){
            
            if(x>y){
                win();
                cout<<"player 1 won this round"<<endl;
            }
            else if(y>x){
                lose();
                cout<<"player 2 won this round"<<endl;
            }
            else if(x==y){
                cout<<"TIE"<<endl;
            }
        }

};


int main()
{
    srand(time(0)); 
    int round = 5;
    DiceGame d;
    d.setRound(round);

    Player p1(0,round);
    p1.setComputer();

    Player p2(0,round);

    // cout<<"Player 1 rolled the dice: "<<p1.throwDice()<<endl;
    // cout<<"Player 2 rolled the dice: "<<p2.throwDice()<<endl;
    
    // int x = p1.throwDice();
    // cout<<x<<endl;
    // int y = p2.throwDice();
    // cout<<y<<endl;


    // p1.play(x,y);

    int x, y;

    for(int i=1;i<=round;i++){
        cout<<"Round "<<i<<endl;
        x = p1.throwDice(); 
        y = p2.throwDice();
        cout<<"Player 1 rolled the dice: "<<x<<" | "<<"Player 2 rolled the dice: "<<y<<endl;

        p1.play(x,y);

        if(p1.getIP() == 0 || p2.getIP() == 0){
            break;
        }
    }

    int s1 =p1.getScore(), s2 = p2.getScore();

    cout<<"Final scores:"<<endl;
    cout<<"Player 1: "<<s1<<" ||  "<<"Player 2: "<<s2<<endl;

    if(s1>s2){
        cout<<"Player 1 won the game!!"<<endl;
    }
    else if(s1<s2){
        cout<<"Player 2 won the game!!"<<endl;
    }
    else if(s1 == s2){
        cout<<"Game tied!!"<<endl;
    }

    return 0;
}