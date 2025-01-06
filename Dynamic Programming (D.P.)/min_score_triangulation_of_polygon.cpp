// in this question we have been given an values array which represent vertice of a polygon(like triangle,sqaure,and more). and return have to make that polygon into the triangle by connecting vectice and return the min score of all the triangle. score can be obtained by multiple all it three vertices.

#include<bits/stdc++.h>
using namespace std;

// int solve(vector<int> &values,int i,int j){
//     if(i+1 == j) return 0;

//     int ans = INT_MAX;
//     cout<<"hello"<<endl;
//     for(int k = i+1;k < j;k++){
//         ans = min(ans,(values[i]*values[j]*values[k])+solve(values,i,k)+solve(values,k,j));
//     }
//     return ans;
// }

// int solve(vector<int> &values,int i,int j,vector<vector<int>> &dp){
//     if(i+1 == j) return 0;

//     if(dp[i][j] != -1) return dp[i][j];
//     int ans = INT_MAX;
//     cout<<"hello"<<endl;
//     for(int k = i+1;k < j;k++){
//         ans = min(ans,(values[i]*values[j]*values[k])+solve(values,i,k,dp)+solve(values,k,j,dp));
//     }
//     dp[i][j] = ans;
//     return dp[i][j];
// }

int find(vector<int> &values){
    int n = values.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    // return solve(values,0,n-1,dp);

    for(int i = n-1;i >= 0;i--){
        for(int j = i+2;j < n;j++){
            int ans = INT_MAX;
            for(int k = i+1;k < j;k++){
                ans = min(ans,(values[i]*values[j]*values[k])+dp[i][k]+dp[k][j]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][n-1];
}


int main(){
    vector<int> values = {3,7,4,5};
    cout<<find(values);
    return 0;
}