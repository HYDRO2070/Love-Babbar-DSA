// we have been given a string we ahve to partion in a way that the string is palindrome and return it.

#include<bits/stdc++.h>
using namespace std;

// bool checkpalindrome(string s,int b,int e){
//     if(b == e) return true;
//     if(b+1 == e){
//         if(s[b] == s[e]) return true;
//         return false;
//     }
//     // cout<<b<<" "<<e<<endl;
//     for(int i = b;i <= ((e)/2);i++){
//         if(s[i] != s[e-1-i]) return false;
//     }
//     // cout<<"Hello"<<endl;
//     return true;
// }

// string to_string(string s,int i,int j){
//     string ans = "";
//     while(i <= j){
//         ans += s[i];
//         i++;
//     }
//     return ans;
// }
// int main(){
//     string s = "aaab";
//     vector<vector<string> > ans;
//     for(int i = 0;i < s.size();i++){
//         vector<string> temp;
//         int j = 0;
//         // if(j+i > s.size()) break;
//         while(j < s.size()){
//             if(j+i >= s.size()-1){
//                 if(checkpalindrome(s,j,s.size()-1)){
//                     temp.push_back(to_string(s,j,s.size()-1));
//                 }
//                 j = s.size()+1;
//                 continue;
//             }
//             if(checkpalindrome(s,j,j+i)){
//                     temp.push_back(to_string(s,j,j+i));
//                 }
//             if(i == 0){
//                 j++;
//                 continue;
//             }
//             j += i;
//         }
//         if(temp.size() > 0){
//             ans.push_back(temp);
//         }
//     }
//     for(int i = 0;i < ans.size();i++){
//         for(int j = 0;j < ans[i].size();j++){
//             cout<<ans[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     // cout<<checkpalindrome(s,0,s.size());
//     return 0;
// }
vector<vector<string> > ans;

bool ispalindrom(string s){
    string t = s;
    reverse(t.begin(),t.end());
    return t == s;
}

void part(string &s,vector<string> &temp,int i){
    if(i == s.size()){
        ans.push_back(temp);
        return;
    }
    for(int j = i;j < s.size();j++){
        if(ispalindrom(s.substr(i,j-i+1))){
            temp.push_back(s.substr(i,j-i+1));
            part(s,temp,j+1);
            temp.pop_back();
        }
    }

}

void partition(string s){
    vector<string> temp;
    part(s,temp,0);
}


int main(){
    string s = "aaab";
    partition(s);
    for(int i = 0;i < ans.size();i++){
        for(int j = 0;j < ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}