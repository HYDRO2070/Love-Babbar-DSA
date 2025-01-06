// in this question we have been given two string and we have to find longest common subsequence from both string.


#include<bits/stdc++.h>
using namespace std;

// int solve(string &s1,string &s2,int i,int j,vector<vector<int>> &dp){
//     if(i >= s1.size() || j >= s2.size()) return 0;
//     if(dp[i][j] != -1) return dp[i][j];
//     cout<<"hello"<<endl;
//     int ans = 0;
//     if(s1[i] == s2[j])
//         ans = 1 + solve(s1,s2,i+1,j+1,dp);
//     else
//         ans = max(solve(s1,s2,i+1,j,dp),solve(s1,s2,i,j+1,dp));
//     return dp[i][j] = ans;
    
// }

int find(string s1,string s2){
    int n = s1.size();
    int m = s2.size();
    // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    // return solve(s1,s2,0,0,dp);

    // for(int i = n-1;i >= 0;i--){
    //     for(int j = m-1;j >= 0;j--){
    //         int ans = 0;
    //         if(s1[i] == s2[j])
    //             ans = 1 + dp[i+1][j+1];
    //         else
    //             ans = max(dp[i+1][j],dp[i][j+1]);
    //         dp[i][j] = ans;
    //     }
    // }
    // return dp[0][0];
    vector<int> next(m+1,0);
    vector<int> curr(m+1,0);
    for(int i = n-1;i >= 0;i--){
        for(int j = m-1;j >= 0;j--){
            int ans = 0;
            if(s1[i] == s2[j])
                ans = 1 + next[j+1];
            else
                ans = max(next[j],curr[j+1]);
            curr[j] = ans;
        }
        next = curr;
    }
    return next[0];
}

int main(){
    string s1 = "abcdefghijklmnop";
    string s2 = "aflpe";
    cout<<find(s1,s2)<<endl;
    return 0;
}