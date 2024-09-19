#include<bits/stdc++.h>
using namespace std;

void print(stack<int> s){
    int size = s.size();
    for(int i = 0;i < size;i++){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

void sorted(stack<int> &s,int val){
    if(s.empty() || s.top() < val){
        s.push(val);
        return;
    }
    int temp = s.top();
    s.pop();
    sorted(s,val);
    s.push(temp);
}

void sort(stack<int> &s){
    if(s.empty()){
        return;
    }
    int temp = s.top();
    s.pop();
    sort(s);
    sorted(s,temp);
}

int main(){
    // 2,4,6,1,87,5,343,66,-1
    stack<int> s;
    s.push(2);
    s.push(4);
    s.push(6);
    s.push(1);
    s.push(87);
    s.push(5);
    s.push(343);
    s.push(66);
    s.push(-1);
    print(s);
    sort(s);
    print(s);   
    return 0;
}