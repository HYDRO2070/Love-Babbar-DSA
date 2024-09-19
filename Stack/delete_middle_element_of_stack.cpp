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

void delete_middle_element(stack<int> &s,int c,int l){
    if(c == l/2){
        s.pop();
        return;
    }
    int temp = s.top();
    s.pop();
    delete_middle_element(s,c+1,l);
    s.push(temp);
}

int main(){
    stack<int> s;
    int cnt = 0;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    print(s);
    delete_middle_element(s,cnt,s.size());
    print(s);
    return 0;
}