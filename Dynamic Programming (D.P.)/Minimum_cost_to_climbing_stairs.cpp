#include<bits/stdc++.h>
using namespace std;

// // recursive solution
// int solve(long long n){
//     if(n == 0) return 1;
//     if(n < 0) return 0;
//     return solve(n-1) + solve(n-2);
// }


// dp solution
int solve(long long n,int *dp){
    if(n == 0) return 1;
    if(n < 0) return 0;
    if(dp[n] != INT_MAX) return dp[n];
    dp[n] =  solve(n-1,dp) + solve(n-2,dp);
    return dp[n];
}



int main(){
    long long n;
    cout<<"Enter the NUm :"<<endl;
    cin>>n;
    int dp[n+1] = {INT_MAX};
    // // recursive function call
    // cout<<solve(n)<<endl;

    //  dp function call
    cout<<solve(n,dp);
    return 0;
}