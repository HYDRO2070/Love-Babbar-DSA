// in this question we have N which represent no of houses and an 2d array which tell the cost to paint at the house using its index like 0index is for first house and same for other . and in paint we have three color with different cost. so our task is to find min cost so that no ajacent house have same color.

#include<bits/stdc++.h>
using namespace std;

// int solve(int n,vector<vector<int>> &cost,int i){
//     if(n < 0) return 0;
//     int num = INT_MAX;
//     if(i != 0)
//         num = cost[n][0] + solve(n-1,cost,0);
//     cout<<"HEllo"<<endl;
//     if(i != 1)
//         num = min(cost[n][1] + solve(n-1,cost,1),num);
//     if(i != 2)
//         num = min(cost[n][2] + solve(n-1,cost,2),num);
//     return num;
// }
 void print(vector<int> &dp){
    for(auto num : dp){
        cout<<num<<" ";
    }
    cout<<endl;
}
// int solve(int n,vector<vector<int>> &cost,int i,vector<vector<int>> &dp){
//     // print(dp);
//     if(n < 0) return 0;
//     // if(dp[n] != INT_MAX) return dp[n];
//     if(i != -1 && dp[n][i] != INT_MAX) return dp[n][i];
//     cout<<"HEllo"<<endl;
//     if(i != 0)
//         dp[n][0] = cost[n][0] + solve(n-1,cost,0,dp);
//     if(i != 1)
//         dp[n][1] = cost[n][1] + solve(n-1,cost,1,dp);
//     if(i != 2)
//         dp[n][2] =  cost[n][2] + solve(n-1,cost,2,dp);
    
//     dp[n][i] = min(dp[n][0],min(dp[n][1],dp[n][2]));
//     return dp[n][i];
// }

int find(int n,vector<vector<int>> &cost){
    vector<vector<int>> dp(n,vector<int>(3,0));
    // return solve(n-1,cost,-1,dp);
    dp[0][0] = cost[0][0];
    dp[0][1] = cost[0][1];
    dp[0][2] = cost[0][2];

    for(int i =1;i < n;i++){
        dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + cost[i][0];
        dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + cost[i][1];
        dp[i][2] = min(dp[i-1][0],dp[i-1][1]) + cost[i][2];
    }
    return min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));
}


int main(){
    int n = 3;
    vector<vector<int>> cost = {
        {14,2,11},
        {11,14,5},
        {14,3,10}
    };
    cout<<find(n,cost);
    return 0;
}