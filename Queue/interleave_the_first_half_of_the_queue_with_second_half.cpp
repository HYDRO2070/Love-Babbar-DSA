// In this question we have been given a queue and we have to mix first part with second part ans return a new queue and only using stack.

#include<bits/stdc++.h>
using namespace std;

void print(queue<int> q){
    int size = q.size();
    for(int i=0;i<size;i++){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

// using another queue not stack
// void find(queue<int> &q){
//     int size = q.size()/2;
//     queue<int> n;
//     q.push(-1);
//     for(int i = 0;i<size;i++){
//         n.push(q.front());
//         q.pop();
//     }
//     print(n);
//     while(q.front() != -1){
//         if(!n.empty()){
//         q.push(n.front());
//         n.pop();}
//         q.push(q.front());
//         q.pop();
//     }
//     q.pop();
// }


// using stack;
void find(queue<int> &q){
    stack<int> s;
    int size = q.size()/2;
    for(int i = 0;i < size;i++){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    for(int i = 0;i < q.size()-size;i++){
        q.push(q.front());
        q.pop();
    }
    for(int i = 0;i < size;i++){
        s.push(q.front());
        q.pop();
    }
    q.push(-1);
    while(q.front() != -1){
        if(!s.empty()){
            q.push(s.top());
            s.pop();
        }
        q.push(q.front());
        q.pop();
    }
    q.pop();
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    print(q);
    find(q);
    print(q);
    return 0;
}