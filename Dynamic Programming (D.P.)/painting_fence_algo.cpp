// in this question we havebeen given two input n and k where n is no of posts and k is no of color and we have to determine the no of ways to color all the post such that no more than two adjacnet post have same color.

#include<bits/stdc++.h>
using namespace std;

// using recursion
// int solve(int n,int k,vector<int> &dp){
//     if(n == 1) return k;
//     if(n == 2) return k*k;
//     if(dp[n] != -1) return dp[n];
//     dp[n] =  solve(n-2,k,dp)*(k-1) + solve(n-1,k,dp)*(k-1);
//     return dp[n];
// }

// using dp
int solve(int n,int k){
    // vector<int> dp(n+1,-1);
    // dp[1] = k;
    // dp[2] = k*k;

    // for(int i = 3;i <= n;i++){
    //     dp[i] = (dp[i-2] + dp[i-1])*(k-1);
    // }
    // return dp[n];

    int a = k;
    int b = k * k;
    for(int i = 3;i <= n;i++){
        int c = (a + b)*(k-1);
        a = b;
        b= c;
    }
    return b;
}


int main(){
    int n = 4,k = 3;
    // vector<int> dp(n+1,-1);
    // cout<<solve(n,k,dp);

    cout<<solve(n,k);
    return 0;
}