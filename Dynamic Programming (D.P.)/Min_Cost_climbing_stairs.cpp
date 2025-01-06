// we can start from 0th or 1th stair.
// we have to pay the cost of the current stair to move forward.
// we can only move 1 or 2 step
// return minimum cost to reach top floor.

#include<bits/stdc++.h>
using namespace std;

// recursive solution
// int solve(int *arr,int size,int i){
//     if(size+1 <= i) return 0;
//     return min(solve(arr,size,i+1),solve(arr,size,i+2)) + arr[i];
// }


// // dp solution
// int solve(int *arr,vector<int> &dp,int n){
//     if(n == 0) return arr[n];
//     if(n == 1) return arr[n];
//     if(dp[n] != INT_MAX) return dp[n];
//     dp[n] = min(solve(arr,dp,n-1),solve(arr,dp,n-2)) + arr[n];
//     return dp[n];
// }


// dp solution reducing space
// int solve(int *cost,int n){
//     vector<int> dp(n+1);
//     dp[0] = cost[0];
//     dp[1] = cost[1];
//     for(int i = 2;i <= n;++i){
//         dp[i] = min(dp[i-1],dp[i-2])+cost[i];
//     }
//     return dp[n];
// }


int main(){
    int cost[10] = {1,100,1,1,1,100,1,1,100,1};
    int n = 10;
    // vector<int> dp(n+1,INT_MAX);
    // // recursive call
    // cout<<solve(arr,10,0);

    // dp call
    // cout<<solve(cost,dp,10-1); 


    // cout<<solve(cost,n-1); 

// best solution with time - O(N) and space - O(1)
    // int first = cost[0];
    // int second = cost[1];
    
    // for(int i = 2;i < n;++i){
    //     int third = min(first,second) + cost[i];
    //     first = second;
    //     second = third;
    // }
    // cout<<second<<endl;

    return 0;
}