#include<bits/stdc++.h>
using namespace std;

class Queue{
    int *arr;
    int *front;
    int *rear;
    int size;
    int *next;
    int free;
    int as;
    public:

    Queue(int n,int s){
        as = n;
        arr = new int[s];
        front = new int[n];
        rear = new int[n];
        next = new int[s];
        size = s;
        free = 0;
        for(int i = 0;i < n;i++){
            front[i] = -1;
            rear[i] = -1;
        }
        for(int i = 0;i < s;i++){
            next[i] = i+1;
        }
        next[s-1] = -1;
    }
    void push(int val,int n){
        if(free == -1){
            cout<<"OverFlow"<<endl;
            return;
        }
        int index = free;
        free = next[index];
        if(front[n-1] == -1){
            front[n-1] = index;
        }
        else{
            next[rear[n-1]] = index;
        }
        next[index] = -1;
        rear[n-1] = index;
        arr[index] = val;

    }

    // 0 2 3 4 5 0 
    // 1 -1 3 -1 -1 -1
    // 1 2 4
    // 1 3 4

    void pop(int n){
        if(front[n-1] == -1){
            cout<<"UnderFlow - "<<n<<endl;
            return;
        }
        int index = front[n-1];
        front[n-1] = next[index];
        arr[index] = 0;
        next[index] = free;
        free = index;
        if(front[n-1] == -1){
            rear[n-1] = -1;
        }

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
            cout<<front[i]<<" ";
        }
        cout<<endl;
        for(int i = 0;i < as;i++){
            cout<<rear[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Queue *q = new Queue(3,6);
    q->push(1,1);
    q->push(2,1);
    q->push(3,2);
    q->push(4,2);
    q->push(6,3);
    q->pop(1);
    q->pop(1);
    q->pop(1);
    q->push(1,1);
    q->pop(1);
    q->pop(2);
    q->pop(2);
    q->pop(2);
    q->pop(3);
    q->pop(3);
    q->pop(3);
    q->print();
    return 0;
}