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
void reversal(queue<int> &q,int i,int k){
    if(i == k+1) return;
    int temp = q.front();
    q.pop();
    reversal(q,i+1,k);
    q.push(temp);
}

void rev(queue<int> &q,int k){
    reversal(q,1,k);
    for(int i = 1;i <= q.size()-k;i++){
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
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
    rev(q,4);
    print(q);
    return 0;
}