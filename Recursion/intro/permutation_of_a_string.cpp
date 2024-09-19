// combination of string. and i won't say anymore.

#include<bits/stdc++.h>
using namespace std;

void find(string s,int i,vector<string>& ans){
    if(i >= s.size()){
        ans.push_back(s);
        return;
    }
    // find(s,i+1,a,ans);
    for(int j = i;j < s.size();j++){
        string temp = s;
        swap(temp[j],temp[i]);
        find(temp,i+1,ans);
    }
}

int main(){
    string s = "abc";
    // string a = "";
    vector<string> ans;
    find(s,0,ans);
    for(int i = 0;i < ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}