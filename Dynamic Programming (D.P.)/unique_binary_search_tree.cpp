// in this question we have been given N which represent the number of node of a tree. we have to retrun the no of unique BST make by the n nodes.

#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
// int solve(int n,vector<int> &dp){
//     if(n == 0 || n == 1) return 1;
//     if(dp[n] != -1) return dp[n];
//     int ans = 0;
//     cout<<"ekke"<<endl;
//     for(int i = 1;i <=n;i++){
//         ans += solve(i-1,dp) * solve(n-i,dp);
//     }
//     return dp[n] = ans;
// }

int find(int N){
    vector<int> dp(N+1,-1);
    // return solve(N,dp);
    dp[0] = dp[1] = 1;

    for(int j = 2;j <= N;j++){
        int ans = 0;
        for(int i = 1;i <=j;i++){
            ans += dp[i-1] * dp[j-i];
        }
        dp[j] = ans;
    }
    return dp[N];
}

// int numTilings(int n) {
//         vector<int> dp(n+1,0);
//         dp[0] = 1;
//         dp[1] = 1;

//         for(int i = 2;i <= n;i++){
//             int ans = 0;
//             for(int j = 1;j <= i;j++){
//                 ans += (dp[j-1]*dp[i-j])%MOD;
//             }
//             dp[i] = ans;
//         }
//         return dp[n];
//     }

int main(){
    int N = 1000;
    cout<<find(N)<<endl;
    // cout<<numTilings(N)<<endl;
    return 0;
}