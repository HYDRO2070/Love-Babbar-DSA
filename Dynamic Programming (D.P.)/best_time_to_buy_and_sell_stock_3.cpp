// same as previous question but in this question we can have almost two transtion only not more not less.

#include <bits/stdc++.h>
using namespace std;

// int solve(vector<int> &arr,int index,int buy,int n,vector<vector<vector<int>>> &dp){
//     if(index >= arr.size() || n == 0) return 0;
//     if(dp[index][buy][n] != -1) return dp[index][buy][n];
//     cout<<"hello"<<endl;
//     int ans = 0;

//     if(buy)
//         ans = solve(arr,index+1,0,n,dp) - arr[index];
//     else
//         ans = max(ans,arr[index] + solve(arr,index+1,1,n-1,dp));

//     ans = max(ans,solve(arr,index+1,buy,n,dp));
//     dp[index][buy][n] = ans;
//     return dp[index][buy][n];
// }

int find(vector<int> &arr)
{
    int n = arr.size();
    // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
    // return solve(arr,0,1,2,dp);

    // for (int index = n - 1; index >= 0; index--)
    // {
    //     for (int buy = 0; buy <= 1; buy++)
    //     {
    //         for (int limit = 1; limit <= 2; limit++)
    //         {
    //             int ans = 0;

    //             if (buy)
    //                 ans = dp[index + 1][0][limit] - arr[index];
    //             else
    //                 ans = max(ans, arr[index] + dp[index + 1][1][limit - 1]);

    //             ans = max(ans, dp[index + 1][buy][limit]);
    //             dp[index][buy][limit] = ans;
    //         }
    //     }
    // }
    vector<vector<int>> next(2,vector<int>(3,0));
    vector<vector<int>> curr(2,vector<int>(3,0));

    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int limit = 1; limit <= 2; limit++)
            {
                int ans = 0;

                if (buy)
                    ans = next[0][limit] - arr[index];
                else
                    ans = max(ans, arr[index] + next[1][limit - 1]);

                ans = max(ans, next[buy][limit]);
                curr[buy][limit] = ans;
            }
        }
        next = curr;
    }

    
    return next[1][2];
}

int main()
{
    vector<int> arr = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << find(arr) << endl;
    return 0;
}