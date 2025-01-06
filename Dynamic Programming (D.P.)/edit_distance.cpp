// we have given two string w1 and w2 and we can apply opration like replcae,delete or insert each opration cost 1 point. we have to return minimum cost to convert w1 to w2;

#include <bits/stdc++.h>
using namespace std;

// int solve(string w1,string w2,int i,int j,vector<vector<int>> &dp){
//     if(j >= w2.size()){
//         return w1.size()-i;
//     }
//     if(i >= w1.size()){
//         return w2.size()-j;
//     }
//     if(dp[i][j] != -1) return dp[i][j];
//     cout<<"hello"<<endl;
//     int ans = INT_MAX;
//     if(w1[i] == w2[j])
//         return solve(w1,w2,i+1,j+1,dp);
//     else{
//         ans = min(ans,1 + solve(w1,w2,i,j+1,dp));
//         ans = min(ans,1 + solve(w1,w2,i+1,j+1,dp));
//         ans = min(ans,1 + solve(w1,w2,i+1,j,dp));
//     }
//     return dp[i][j] = ans;
// }

int find(string &w1, string &w2)
{
    int n = w1.size();
    int m = w2.size();
    // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // return solve(w1,w2,0,0,dp);
    // for (int j = 0; j < m; j++)
    // {
    //     dp[n][j] = w2.size() - j;
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     dp[i][m] = w1.size() - i;
    // }
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     for (int j = m - 1; j >= 0; j--)
    //     {
    //         if (w1[i] == w2[j])
    //             dp[i][j] = dp[i + 1][j + 1];
    //         else
    //         {
    //             int ans = INT_MAX;
    //             ans = min(ans, 1 + dp[i][j + 1]);
    //             ans = min(ans, 1 + dp[i + 1][j + 1]);
    //             ans = min(ans, 1 + dp[i + 1][j]);
    //             dp[i][j] = ans;
    //         }
    //     }
    // }
    // return dp[0][0];

    vector<int> next(m + 1, 0);
    vector<int> curr(m + 1, 0);
    for (int j = 0; j < m; j++)
    {
        next[j] = w2.size() - j;
    }
    // curr[m] = 1;
    // next[m] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            curr[m-1] = n-i-1;
            int ans = INT_MAX;
            if (w1[i] == w2[j])
                ans = next[j + 1];
            else
            {
                ans = min(ans, 1 + curr[j + 1]);
                ans = min(ans, 1 + next[j + 1]);
                ans = min(ans, 1 + next[j]);
            }
            curr[j] = ans;
        }
        next = curr;
    }
    return next[0];
}

int main()
{
    string w1 = "horse";
    string w2 = "ros";
    cout << find(w1, w2) << endl;
    return 0;
}