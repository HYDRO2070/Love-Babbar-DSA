// in this question we have been give the size or length of the rod n and we have to create segments of that of x, y, or z length. so we have to return the maximum segment we can make the rod into segments.

#include<bits/stdc++.h>
using namespace std;

// using recursion
// int solve(int n,vector<int> &arr,int s,vector<int> &dp){
//     if(n == 0){
//         return s;
//     }
//     if(dp[n] != -1) return dp[n];
//     cout<<dp[n]<<endl;
//     int x = -1,y = -1,z = -1;
//     if(n-arr[0] >= 0)
//     x = solve(n-arr[0],arr,s+1,dp);
//     if(n-arr[1] >= 0)
//     y = solve(n-arr[1],arr,s+1,dp);
//     if(n-arr[2] >= 0)
//     z = solve(n-arr[2],arr,s+1,dp);
//     if(x == -1 && y == -1 && z == -1) return -1;
//     dp[n] = max(x,max(y,z));
//     return dp[n];
// }

// using tabulation method
int solve(int n,vector<int> &arr){
    vector<int> dp(n+1,INT_MIN);
    dp[0] = 0;

    for(int i = 1;i <= n;i++){
       
        if(i-arr[0] >= 0)
        dp[i] = max(dp[i],dp[i-arr[0]]+1);
        if(i-arr[1] >= 0)
        dp[i] = max(dp[i],dp[i-arr[1]]+1);
        if(i-arr[2] >= 0)
        dp[i] = max(dp[i],dp[i-arr[2]]+1);
    }
    return (dp[n] >= 0) ? dp[n] : -1;
}





int main(){
    int n = 8;
    vector<int> arr = {2,2,2};
    // using recursion
    // cout<<solve(n,arr,0);

    // using dp
    // vector<int> dp(n+1,-1);
    // cout<<solve(n,arr,0,dp);

    // using tabulation method
    cout<<solve(n,arr);
    
    return 0;
}