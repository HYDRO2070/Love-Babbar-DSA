#include<bits/stdc++.h>
using namespace std;

string reverse_stack(string s){
    string ans = "";
    stack<char> c;
    for(int i = 0;i < s.size();i++){
        c.push(s[i]);
    }
    for(int i = 0;i < s.size();i++){
        ans += c.top();
        c.pop();
    }
    return ans;
}

int main(){
    string s = "humankrow";
    cout<<reverse_stack(s);
    return 0;
}