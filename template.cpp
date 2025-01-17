#include <iostream>
using namespace std;

template<class T>        
class Stack{
    private:
        T *stk;
        int top;
        int size;

    public:
        Stack(int n){
            size = n;
            top = -1;
            stk = new T[size];
        }

        void push(T x);
        T pop();
};


template<class T>
void Stack<T>:: push(T x){
    if(top == size-1){
        cout<<"Stack is full.."<<endl;
    }
    else{
        top++;
        stk[top] = x;
    }
}

template<class T>
T Stack<T>::pop(){
    T x = 0;
    if(top == -1){
        cout<<"Stack is empty..";
    }
    else{
        x = stk[top];
        top--;
    }
}

int main()
{
    Stack<int> s(5);
    s.push(5);
    s.push(1);
    s.push(4);
    s.push(78);
    s.push(10);
    s.push(2);
    return 0;
}