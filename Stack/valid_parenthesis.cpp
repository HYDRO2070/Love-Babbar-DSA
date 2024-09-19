#include<bits/stdc++.h>
using namespace std;

bool valid(string s){
    stack<char> c;
    for(int i = 0;i < s.size();i++){
        if(s[i] == ')'){
            if(c.top() == '('){
                c.pop();
                continue;
            }
            return false;
        }
        else if(s[i] == ']'){
            if(c.top() == '['){
                c.pop();
                continue;
            }
            return false;
        }
        else if(s[i] == '}'){
            if(c.top() == '{'){
                c.pop();
                continue;
            }
            return false;
        }
        else{
            c.push(s[i]);
        }
    }
    if(c.empty()) return true;
    return false;
}

int main(){
    string s = "({[[{()}]])";
    cout<<valid(s);
    return 0;
}