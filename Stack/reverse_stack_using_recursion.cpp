#include<bits/stdc++.h>
using namespace std;

void print(stack<int> s){
    int size = s.size();
    for(int i = 0; i < size;i++){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

void insert(stack<int> &s,int num){
    if(s.empty()){
        s.push(num);
        return;
    }
    int temp = s.top();
    s.pop();
    insert(s,num);
    s.push(temp);
}

void reverse(stack<int> &s){
    if(s.empty()) return;
    int temp = s.top();
    s.pop();
    reverse(s);
    insert(s,temp);
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    print(s);
    reverse(s);
    print(s);
    return 0;
}