#include<bits/stdc++.h>
using namespace std;

class Stack{
    int *arr;
    int free = 0;
    int *top;
    int *next;
    int size = -1;
    int as = -1;
    public:
    Stack(int s,int a){
        size = s;
        as= a;
        arr = new int[s];
        top = new int[a];
        next = new int[s];
        for(int i = 0;i < a;i++){
            top[i] = -1;
        }
        for(int i = 0;i < s;i++){
                next[i] = i+1;
        }
        next[s-1] = -1;
    }

    void push(int val,int s){
        if(free == -1){
            cout<<"StackOverFlow"<<endl;
            return;
        }
        int index = free;
        free = next[index];
        arr[index] = val;
        next[index] = top[s-1];
        top[s-1] = index;
    }
    int pop(int s){
        if(top[s-1] == -1){
            cout<<"StackUnderFlow"<<endl;
            return -1;
        }
        int index = top[s-1];
        int temp = arr[index];
        top[s-1] = next[index];
        arr[index] = 0;
        next[index] = free;
        free = index;
        return temp;
    }
    void print(){
        for(int i = 0;i < size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        for(int i = 0;i < size;i++){
            cout<<next[i]<<" ";
        }
        cout<<endl;
        for(int i = 0;i < as;i++){
            cout<<top[i]<<" ";
        }
        cout<<endl;
    }
};


int main(){
    Stack *s = new Stack(6,3);
    s->push(5,1);
    s->push(5,1);
    s->push(5,2);
    s->print();
    cout<<s->pop(1);
    cout<<s->pop(1);
    cout<<s->pop(1);
    s->print();
    return 0;
}