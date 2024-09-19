// we have been given number and as in the keypad phone a single num can produce three letter like 1 have a,b,c and so.
// so through the number which have been given we have to make every combination of the char.
// the length of num is equal to subsquence of str.

#include<bits/stdc++.h>
using namespace std;

void phone(string s,int i,string a,string maap[],vector<string>& ans){
    if(i >= s.size()){
        if(a.size() > 0)
        ans.push_back(a);
        return;
    }
    string temp = maap[s[i] - '1' -1];
    for(int j = 0;j < temp.size();j++){
        phone(s,i+1,a+temp[j],maap,ans);
    }
}

int main(){
    string num = "45";
    vector<string> ans;
    string a = "";
    string maap[8] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    phone(num,0,a,maap,ans);
    for(int i = 0;i < ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}