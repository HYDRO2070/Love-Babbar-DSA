#include<bits/stdc++.h>
using namespace std;

class circular{
    int *arr;
    int size,front,rear;
    public:

    circular(int val){
        size = val;
        arr = new int[val];
        front = -1;
        rear = -1;
    }
    void push(int val){
        if((rear != -1 && rear == front )|| (front == -1 && rear+1 == size)){
            cout<<"OverFlow"<<endl;
            return;
        }
        rear++;
        if(rear > size-1) rear = (rear + size) % size;
        // cout<<rear<<endl;
        arr[rear] = val;
    }
    void pop(){
        if(front == -1 && rear == -1){
            cout<<"UnderFlow"<<endl;
            return;
        }
        front++;
        if(front >size-1) front = (front + size) % size;
        arr[front] = 0;
        if(front == rear){
            front = -1;
            rear = -1;
        }
    }
    void print(){
        for(int i = 0;i < size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    int getinfro(){
        return front+rear;
    }
};

// 0 1 2 3 4
 


int main(){
    circular *q = new circular(5);
    q->push(1);
    q->push(2);
    q->push(3);
    q->push(4);
    q->push(4);
    q->print();
    q->pop();
    // q->pop();
    q->print();
    q->push(9);
    q->push(19);
    q->push(119);
    q->push(119);
    q->push(119);
    q->print();
    q->pop();
    q->pop();
    q->pop();
    q->pop();
    q->pop();
    q->pop();
    q->pop();
    q->pop();
    // cout<<q->getinfro()<<endl;
    q->print();
    return 0;
}