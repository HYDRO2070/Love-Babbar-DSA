// In this file we are going to study about stack.
// stack is an data structure which follow last in first out rule.
// operation of the stack ar mention below in the program and there implementation.
// there are two ways to use the stack by using STL or by using class. and in class implementation there 
// are two menthod which are linked list and array.

#include<bits/stdc++.h>
using namespace std;

// implementation of stack using class
class Stack{
    public:
    int size;
    int top = -1;
    int *arr;
    Stack(int val){
        this->size = val;
        arr = new int[size];
    }
    int peak(){
        if(top == -1) return -1;
        return arr[top];
    }
    bool isempty(){
        if(top < 0) return true;
        return false;
    }
    bool isfull(){
        if(top == size-1) return true;
        return false;
    }
    void push(int val){
        if(top+1 >= size){
            cout<<"StackOverflow"<<endl;
            return;
        }
        arr[top+1] = val;
        top++;
    }
    int pop(){
        if(top < 0){
            cout<<"StackUnderFlow"<<endl;
            return -1;
        }
        int temp = arr[top];
        arr[top] = 0;
        top--;
        return temp;
    }
    int stacksize(){
        return this->size;
    }
    void print(){
        if(top < -1){
            cout<<" StackUnderFlow"<<endl;
            return;
        }
        for(int i=0;i < this->top;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

void dele(Stack *s){
    delete s;
}

int main(){
    Stack *s = new Stack(5);
    s->push(1);
    s->push(2);
    s->push(3);
    s->push(4);
    cout<<s->pop()<<endl;
    cout<<s->pop()<<endl;
    cout<<s->pop()<<endl;
    cout<<s->pop()<<endl;
    cout<<s->pop()<<endl;
    cout<<s->peak()<<endl;
    cout<<s->isempty()<<endl;
    cout<<s->isfull()<<endl;
    s->print();
    dele(s);
    // int a = 0;
    // stack<int> s;
    // s.push(1);
    // s.push(2);
    // s.push(3);
    // s.pop();
    // cout<<s.empty()<<endl;
    // a = a++;
    // cout<<++a;
    return 0;
}