// given N dices and M face for each dice,number from 1 to M. find the number of ways to get sum X. x is sum of the number from the dice.

#include<bits/stdc++.h>
using namespace std;
// using recursion + memo
// int solve(int n,int m,int x,int sum,vector<vector<int>> &dp){
//     // if(sum == x) return 1;
//     // if(sum > x) return 0;
//     if(n == 0){
//         if(sum == x) return 1;
//         return 0;
//     }
//     if(dp[n][sum] != -1) return dp[n][sum];
//     cout<<"hello"<<endl;
//     int ans = 0;
//     for(int i = 1;i <= m;i++){
//         if(sum+i <= x)
//         ans += solve(n-1,m,x,sum+i,dp);
//     }
//     dp[n][sum] = ans;
//     return dp[n][sum];
// }

// int solve(int n,int m,int x){
//     if(n == 0 && x != 0) return 0;
//     if(x == 0 && n != 0) return 0;
//     if(n == 0 && x == 0) return 1;
//     cout<<"hello"<<endl;
//     int ans = 0;
//     for(int i = 1;i <= m;i++){
//         ans += solve(n-1,m,x-i);
//     }
//     return ans;
// }

int find(int N,int M,int X){
    // vector<vector<int>> dp(N+1,vector<int>(X+1,0));
    vector<int> curr(X+1,0);
    vector<int> prev(X+1,0);
    // return solve(N,M,X);
    // return solve(N,M,X,0,dp);
    // dp[0][X] = 1;
    // for(int n = 1;n <= N;n++){
    //     for(int sum = X;sum >= 0;sum--){
    //         int ans = 0;
    //         for(int i = 1;i <= M;i++){
    //             if(sum+i <= X)
    //             ans += dp[n-1][sum+i];
    //         }
    //         dp[n][sum] = ans;
    //     }
    // }

    prev[X] = 1;
    for(int n = 1;n <= N;n++){
        for(int sum = X;sum >= 0;sum--){
            int ans = 0;
            for(int i = 1;i <= M;i++){
                if(sum+i <= X)
                ans += prev[sum+i];
            }
            curr[sum] = ans;
        }
        prev = curr;
    }
    return prev[0];
}

int main(){
    int N = 3,M = 6,X = 12;
    cout<<find(N,M,X);
    return 0;
}