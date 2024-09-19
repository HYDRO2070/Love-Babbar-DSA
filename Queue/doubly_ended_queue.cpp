#include<bits/stdc++.h>
using namespace std;

// void print(deque<int> q){
//     for(int i = 0;i < q.size();i++){
//         cout<<q.front()<<" ";
//         q.pop_front();
//     }
//     cout<<endl;
// }


class Deque{
    int *arr;
    int front,size,rear;
    public:
    Deque(int val){
        size = val;
        arr = new int[val];
        front = rear = -1;
    }
    void pushfront(int val){
        if((front == 0 && rear == size-1) || rear == (front-1)%(size-1)){
            cout<<"OverFlow "<<val<<endl;
            return;
        }
        else if(rear == -1 && front == -1){
            front = rear = 0;
        }
        else if(front == 0){
            front = size-1;
        }
        else{
            front--;
        }
        arr[front] = val;
    }
    void pushback(int val){
        if((front == 0 && rear == size-1) || rear == (front-1)%(size-1)){
            cout<<"OverFlow "<<val<<endl;
            return;
        }
        else if(rear == -1 && front == -1){
            front = rear = 0;
        }
        else if(rear == size-1){
            front = 0;
        }
        else{
            rear++;
        }
        arr[rear] = val;
    }

    void popfront(){
        if(front == -1){
            cout<<"UnderFlow"<<endl;
            return;
        }
        arr[front] = 0;
        if(front == size-1){
            front = 0;
        }
        else{
            front++;
        }
        if(front == 0){
            front = -1;
        }
    }
    void popback(){
        if(rear == -1){
            cout<<"UnderFlow"<<endl;
            return;
        }
        arr[rear] = 0;
        if(rear == 0){
            rear = size-1;
        }
        else{
            rear--;
        }
        if(rear == size-1){
            rear = -1;
        }
    }

    void print(){
        for(int i = 0;i< size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void value(){
        cout<<front<<" "<<rear<<endl;
    }
};

int main(){
    // deque<int> q;
    // q.push_back(1);
    // q.push_back(2);
    // q.push_back(3);
    // q.push_front(4);
    // q.push_front(5);
    // q.push_front(6);
    // print(q);

    Deque *q = new Deque(6);
    q->pushback(1);
    q->pushback(2);
    q->pushfront(3);
    q->pushfront(4);
    q->pushback(5);
    q->pushback(6);
    q->pushfront(7);
    q->pushfront(8);
    q->print();
    q->popback();
    q->popback();
    q->popback();
    q->popback();
    q->popback();
    q->popfront();
    q->popfront();
    q->popfront();
    q->print();
    q->value();

    return 0;
}