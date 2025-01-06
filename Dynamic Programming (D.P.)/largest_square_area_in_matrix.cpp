// in this we have benn given matrix with n*n size and we have to find the largest rectangle in the matrix and return size of it.

#include <bits/stdc++.h>
using namespace std;

// using recursion
// int solve(vector<vector<int>> &arr,int i,int j,int &maxi){
//     if(i >= arr.size() || j >= arr[0].size()) return 0;

//     int r = solve(arr,i,j+1,maxi);
//     int d = solve(arr,i+1,j+1,maxi);
//     int b = solve(arr,i+1,j,maxi);

//     if(arr[i][j] == 1){
//         int ans = 1+ min(r,min(d,b));
//         maxi = max(maxi,ans);
//         return ans;
//     }
//     else return 0;
// }

// using recursion + dp
// int solve(vector<vector<int>> &arr,int i,int j,int &maxi,vector<vector<int>> &dp){
//     if(i >= arr.size() || j >= arr[0].size()) return 0;
//     if(dp[i][j] != -1) return dp[i][j];
//     cout<<"heeee"<<endl;
//     int r = solve(arr,i,j+1,maxi,dp);
//     int d = solve(arr,i+1,j+1,maxi,dp);
//     int b = solve(arr,i+1,j,maxi,dp);

//     if(arr[i][j] == 1){
//         dp[i][j] = 1+ min(r,min(d,b));
//         maxi = max(maxi,dp[i][j]);
//         return dp[i][j];
//     }
//     else return 0;
// }

int find(vector<vector<int>> &arr)
{
    int maxi = 0;
    int n = arr.size();
    int m = arr[0].size();
    // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    // solve(arr,0,0,maxi,dp);
    // return maxi;

    // for(int i = n-1;i >= 0;i--){
    //     for(int j = m-1;j >= 0;j--){

    //         int r = dp[i][j+1];
    //         int d = dp[i+1][j+1];
    //         int b = dp[i+1][j];

    //         if(arr[i][j] == 1){
    //             dp[i][j] = 1+ min(r,min(d,b));
    //             maxi = max(maxi,dp[i][j]);

    //         }
    //         else dp[i][j] = 0;

    //     }
    // }

    // vector<int> cur(m + 1, 0);
    // vector<int> nxt(m + 1, 0);

    // for (int i = n - 1; i >= 0; i--)
    // {
    //     for (int j = m - 1; j >= 0; j--)
    //     {

    //         int r = cur[j + 1];
    //         int d = nxt[j + 1];
    //         int b = nxt[j];

    //         if (arr[i][j] == 1)
    //         {
    //             cur[j] = 1 + min(r, min(d, b));
    //             maxi = max(maxi, cur[j]);
    //         }
    //         else
    //             cur[j] = 0;
    //     }
    //     nxt = cur;
    // }


    vector<int> cur(m + 1, 0);
    vector<int> nxt(m + 1, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {

            int r = cur[j + 1];
            int d = nxt[j + 1];
            int b = nxt[j];

            if (arr[i][j] == 1)
            {
                cur[j] = 1 + min(r, min(d, b));
                maxi = max(maxi, cur[j]);
            }
            else
                cur[j] = 0;
        }
        nxt = cur;
    }


    return maxi;
}

int main()
{
    vector<vector<int>> arr = {
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0}};
    cout << find(arr);
    return 0;
}