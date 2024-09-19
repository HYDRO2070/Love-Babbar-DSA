#include<bits/stdc++.h>
using namespace std;

// string str(char a){
//     return ""+a;
// }

void subsequence(string s,int i,string a,vector<string>& ans){
    if(i >= s.size()){
        if(a.size() > 0)
        // cout<<a<<endl;
        ans.push_back(a);
        return;
    }
    subsequence(s,i+1,a,ans);
    // a += s[i];
    subsequence(s,i+1,a+s[i],ans);
}

int main(){
    string s = "abc";
    string a = "";
    vector<string> ans;
    subsequence(s,0,a,ans);
    for(int i = 0;i < ans.size();i++){
            cout<<ans[i];
        cout<<endl;
    }
    return 0;
}