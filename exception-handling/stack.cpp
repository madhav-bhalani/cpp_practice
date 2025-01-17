#include <iostream>
using namespace std;

class StackOverFlow: public exception{

};

class StackUnderFlow: public exception{

};

class Stack{
    private:
        int *stack;
        int top = -1;
        int size;

    public:
        Stack(int n){
            size = n;
            stack = new int[size];
        }

        void push(int x){
            if(top==size-1){
                throw StackOverFlow();
            }
            top++;
            stack[top] = x;
        }

        int pop(){
            if(top == -1){
                throw StackUnderFlow();
            }
            return stack[top--];
        }

};

int main()
{
  
    Stack s(5);

    s.push(2);
    s.push(8);
    s.push(5);
    s.push(32);
    s.push(16);

    s.push(1);

    return 0;
}