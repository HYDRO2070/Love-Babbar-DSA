#include<bits/stdc++.h>
using namespace std;

bool redundant(string str){
    stack<char> s;
    for(int i = 0;i < str.size();i++){
        if(str[i] == ')'){
            if(s.top() == '(') return true;
            else{
                int flag = 0;
                while(s.top() != '(' || s.empty()){
                    if((s.top() == '+') || (s.top() == '-') || (s.top() == '*') || (s.top() == '/')) flag = 1;
                    s.pop();
                }
                if(s.empty() || flag == 0) return true;
                s.pop();
            }
        }
        else{
            s.push(str[i]);
        }
    }
    return false;
}

int main(){
    string str = "(a+(a(a+b)))";
    cout<<redundant(str);
    return 0;
}