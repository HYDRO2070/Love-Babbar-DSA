#include<bits/stdc++.h>
using namespace std;

int min_cost_valid(string str){
    stack<char> s;
    int ans = 0;
    for(int i = 0;i < str.size();i++){
        // cout<<"hello"<<endl;
        if(str[i] == '{') s.push(str[i]);
        else{
            if(!s.empty() && s.top() == '{'){
                s.pop();
            }
            else{
                ans++;
            }
        }
    }
    while(!s.empty()){
        ans++;
        s.pop();
    }
    if(ans&1) return -1;
    return ans/2;
}

int main(){
    string str = "}}{{";
    cout<<min_cost_valid(str);
    return 0;
}