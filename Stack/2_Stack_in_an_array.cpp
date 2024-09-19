//we have been given a question where we have to implement two stack using only single array. with there respective operation.

#include<bits/stdc++.h>
using namespace std;

class twostack{
    int top1;
    int top2;
    int size;
    int *arr;
    public:
    twostack(int val){
        this->size = val;
        top1 = -1;
        top2 = val;
        arr = new int[val];
    }
    void push1(int val){
        if(top1+1 >= top2){
            cout<<"StackOverFlow - 1"<<endl;
        }
        top1++;
        arr[top1] = val;

    }
    void push2(int val){
        if(top2-1 <= top1){
            cout<<"StackOverFlow - 2"<<endl;
            return;
        }
        top2--;
        arr[top2] = val;
        
    }
    void pop1(){
        if(top1 == -1){
            cout<<"StackUnderFlow - 1"<<endl;
        }
        arr[top1] = 0;
        top1--;
    }
    void pop2(){
        if(top2 == size){
            cout<<"StackUnderFlow - 2"<<endl;
        }
        arr[top2] = 0;
        top2++;
    }
    int peak1(){
        if(top1 == -1){
            cout<<"StackUnderFlow - 1"<<endl;
            return -1;
        }
        return arr[top1];
    }
    int peak2(){
        if(top2 == size){
            cout<<"StackUnderFlow - 2"<<endl;
            return -1;
        }
        return arr[top2];
    }
    void print1(){
        if(top1 == -1){
            cout<<"StackUnderFlow - 1"<<endl;
            return;
        }
        for(int i=0;i <= top1;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void print2(){
        if(top2 == -2){
            cout<<"StackUnderFlow - 2"<<endl;
            return;
        }
        for(int i=top2;i < size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    twostack *s = new twostack(5);
    s->push1(1);
    s->push1(2);
    s->push1(3);
    s->push2(2);
    s->push2(1);
    s->push2(1);
    s->print1();
    s->print2();
    cout<<s->peak1()<<endl;
    cout<<s->peak2()<<endl;
    return 0;
}