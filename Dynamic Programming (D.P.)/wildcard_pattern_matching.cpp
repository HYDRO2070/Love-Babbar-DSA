// in this question we have been given a string and a patter we have to return true or false. meaning if the mattern satisfy the string than return true otherwise false. there are two special characteer in the pattern (?) , (*).  ? replcae a single character and * can replace any number of character and empty string also.

#include<bits/stdc++.h>
using namespace std;

bool solve(string str,string pattern,int i,int j,vector<vector<int>> &dp){
    if(i >= str.size()){
        for(j;j<pattern.size();j++){
            if(pattern[j] != '*') return false;
        }
        return true;
    }
    if(j >= pattern.size()) return (i >= str.size());
    if(dp[i][j] != -1) return dp[i][j];
    cout<<"hello"<<endl;
    bool ans = false;
    if(str[i] == pattern[j] || pattern[j] == '?')
        ans = solve(str,pattern,i+1,j+1,dp);
    else if(pattern[j] == '*'){

        ans |= solve(str,pattern,i,j+1,dp);
        ans |= solve(str,pattern,i+1,j,dp);
    }
    else ans = false;
    return dp[i][j] = ans;

}

bool find(string str,string pattern){
    int n = str.size();
    int m = pattern.size();
    vector<vector<int>> dp(n,vector<int>(m,0));
    // return solve(str,pattern,0,0,dp);
}

int main(){
    string str = "abcde";
    string pattern = "a*c?e";
    if(find(str,pattern)) cout<<"True"<<endl;
    else cout<<"False"<<endl;
    return 0;
}