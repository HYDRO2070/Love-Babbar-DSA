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

int main(){
    stack<int> s;
    int num = 1;
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    print(s);
    insert(s,num);
    print(s);
    return 0;
}