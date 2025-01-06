// same as previous question we have to buy and sell stock with maximum profit.but in this question we can buy and sell multiple time. but the condtion is we can buy only one stock meaning after buying we have to sell the stock to buy again.

#include<bits/stdc++.h>
using namespace std;

// int solve(vector<int> &arr,int index,int buy,vector<vector<int>> &dp){
//     if(index >= arr.size()) return 0;
//     if(dp[index][buy] != -1) return dp[index][buy];
//     cout<<"hello"<<endl;
//     int ans = 0;

//     if(buy)
//         ans = solve(arr,index+1,0,dp) - arr[index];
//     else
//         ans = max(ans,arr[index] + solve(arr,index+1,1,dp));
    
//     ans = max(ans,solve(arr,index+1,buy,dp));
//     dp[index][buy] = ans;
//     return dp[index][buy];
// }

int find(vector<int> &arr){
    int n = arr.size();
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    // return solve(arr,0,1,dp);
    
    for(int index = n-1;index >= 0;index--){
        for(int buy = 0;buy <= 1;buy++){
            int ans = 0;

            if(buy)
                ans = dp[index+1][0] - arr[index];
            else
                ans = max(ans,arr[index] + dp[index+1][1]);
            
            ans = max(ans,dp[index+1][buy]);
            dp[index][buy] = ans;
        }
    }
    return dp[0][1];

    // pair<int,int> next = {0,0};
    // pair<int,int> curr = {0,0};
    // for(int index = n-1;index >= 0;index--){
    //     for(int buy = 0;buy <= 1;buy++){
    //         int ans = 0;

    //         if(buy)
    //             ans = next.first - arr[index];
    //         else
    //             ans = max(ans,arr[index] + next.second);
    //         int temp;
    //         if(buy) temp = next.second;
    //         else temp = next.first;
    //         ans = max(ans,temp);
    //         if(buy) curr.second = ans;
    //         else curr.first = ans;
    //     }
    //     next = curr;
    // }
    // return next.second;
}


int main(){
    vector<int> arr = {7,1,5,3,6,4};    
    cout<<find(arr)<<endl;
    return 0;
}