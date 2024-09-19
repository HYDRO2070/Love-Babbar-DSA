#include<bits/stdc++.h>
using namespace std;

void print(queue<int> q){
    int size = q.size();
    for(int i = 0;i < size;i++){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}
void reversal(queue<int> &q){
    if(q.empty()) return;
    int temp = q.front();
    q.pop();
    reversal(q);
    q.push(temp);
}

int main(){
    queue<int> q;
    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);
    print(q);
    reversal(q);
    print(q);
    return 0;
}