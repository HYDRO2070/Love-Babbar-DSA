#include<bits/stdc++.h>
using namespace std;

string find(string s){
    map<char,int> m;
    queue<char> q;
    string ans = "";
    for(int i = 0;i < s.size();i++){
        m[s[i]]++;
        if(m[s[i]] == 1){
            ans += s[i];
        }
        else{
            ans += '#';
        }
    }
    return ans;
    // for(int i = 0;i < s.size();i++){
    //     if(m[arr[]])
    // }
    
}

int main(){
    string s = "aabc";
    cout<<find(s);
    return 0;
}