// i won't explain it to u. u should now what palindrom mean's. and if u don't know so just search in chatgpt.

#include<bits/stdc++.h>
using namespace std;

bool check(string s,int l){
    if(l > s.size() -1-l){
        return true;
    }
    if(s[l] != s[s.size() -1-l])
    return false;

    return check(s,l+1);
}

int main(){
    string name = "bababbab";
    cout<<check(name,0);
    return 0;
}