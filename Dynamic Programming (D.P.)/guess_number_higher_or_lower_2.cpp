// In this question  we are playing a guessing game where we have to pick a number fomr 1 to n. and if we pick lower or higher we have to pay the pricee of the current number and try again. so what we have to do is return the minimum amount of money regardless of what number i pick.

#include <bits/stdc++.h>
using namespace std;

// int solve(int start,int end,vector<vector<int>> &dp){
//     if(start >= end) return 0;
//     if(dp[start][end] != -1) return dp[start][end];
//     cout<<"hello world"<<endl;
//     int ans = INT_MAX;
//     for(int i = start;i <= end;i++){
//         ans = min(ans,i + max(solve(start,i-1,dp),solve(i+1,end,dp)));
//     }
//     return dp[start][end] = ans;
// }

int find(int N)
{
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
    // return solve(1,N,dp);

    for (int start = N; start >= 1; start--)
    {
        for (int end = start; end <= N; end++)
        {   if(start >= end) continue;
            int ans = INT_MAX;
            for (int i = start; i <= end; i++)
            {
                ans = min(ans, i + max(dp[start][i - 1], dp[i + 1][end]));
            }
            dp[start][end] = ans;
        }
    }
    return dp[1][N];
}

int main()
{
    int N = 10;
    cout << find(N) << endl;
    return 0;
}