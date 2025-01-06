// this question is same as previous questio but in this we have given k which means we can only buy and sell k time not more or less.
// in this question we can use previous method. so we are going to implement different method here.

#include<bits/stdc++.h>
using namespace std;

// int solve(vector<int> &arr,int operation,int index,vector<vector<int>> &dp){
//     if(index >= arr.size()) return 0;
//     if(operation == 0) return 0;
//     if(dp[index][operation] != -1) return dp[index][operation];
//     cout<<"hello"<<endl;
//     int ans = 0;
//     if(operation&1)
//         ans = max(ans,arr[index] + solve(arr,operation-1,index+1,dp));
//     else
//         ans = solve(arr,operation-1,index+1,dp) - arr[index];
//     ans = max(ans,solve(arr,operation,index+1,dp));
//     return dp[index][operation] = ans;
// }

int find(vector<int> &arr,int k){
    int n = arr.size();
    // vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));
    // return solve(arr,2*k,0,dp);
    vector<int> next(2*k+1,0);
    vector<int> curr(2*k+1,0);
    for(int index = n-1;index >= 0;index--){
        for(int operation = 1;operation <= 2*k;operation++){
            int ans = 0;
            if(operation&1)
                ans = max(ans,arr[index] + next[operation-1]);
            else
                ans = next[operation-1] - arr[index];
            ans = max(ans,next[operation]);
            curr[operation] = ans;
        }
        next = curr;
    }
    return next[2*k];

}

int main()
{
    vector<int> arr = {3, 3, 5, 0, 0, 3, 1, 4};
    int k = 2;
    cout << find(arr,k) << endl;
    return 0;
}