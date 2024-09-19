#include<bits/stdc++.h>
using namespace std;

class Queue{
    int *arr;
    int size,front,rear;
    public:

    Queue(int val){
        size = val;
        arr = new int[val];
        front = -1;
        rear = -1;
    }
    void enqueue(int val){
        if(rear+1 == size){
            cout<<"OverFlow"<<endl;
            return;
        }
        rear++;
        arr[rear] = val;
    }
    void dequeue(){
        if(front+1 == -1 || front == rear){
            cout<<"UnderFlow"<<endl;
            return;
        }
        front++;
        arr[front] = 0;
        if(front == rear){
            front = rear = -1;
        }
    }
    int Front(){
        if(front == -1){
            return -1;
        }
        return arr[front];
    }
    int back(){
        if(rear == -1){
            return -1;
        }
        return arr[rear];
    }
    bool isempty(){
        if(front == -1) return true;
        return false;
    }
    int Size(){
        return size;
    }
    void print(){
        for(int i = 0;i < size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};

int main(){

    // STL Implementation
    // queue<int> s;
    // s.push(1);
    // s.push(2);
    // s.push(3);
    // cout<<s.front();
    
    Queue *q = new Queue(5);
    q->enqueue(1);
    q->enqueue(2);
    cout<<q->Front()<<endl;
    cout<<q->back()<<endl;
    q->enqueue(3);
    q->dequeue();
    q->dequeue();
    q->dequeue();
    q->dequeue();
    cout<<q->Front()<<endl;
    cout<<q->back()<<endl;
    q->print();
    return 0;
}