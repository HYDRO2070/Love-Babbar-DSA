// IN this question we have been given an array of the leaf node have we have to buid the tree by choosing the max of left subtree and right subtree. and doing so we will have different types of tree and we have to return the min value of the root among the rest.


#include<bits/stdc++.h>
using namespace std;

// int solve(vector<int> &arr,int i,int j,map<pair<int,int>,int> &maxi,vector<vector<int>> &dp){
//     if(i == j) return 0;
//     if(dp[i][j] != -1) return dp[i][j];
//     int ans = INT_MAX;
//     cout<<"hello"<<endl;
//     for(int k = i;k < j;k++){
//         ans = min(ans,maxi[{i,k}] * maxi[{k+1,j}]+ solve(arr,i,k,maxi,dp) + solve(arr,k+1,j,maxi,dp));
//     }
//     return dp[i][j] = ans;
// }

int find(vector<int> &arr){
    int n = arr.size();
    map<pair<int,int>,int> maxi;
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i = 0;i < n;i++){
        maxi[{i,i}] = arr[i];
        for(int j = i+1;j < n;j++){
            maxi[{i,j}] = max(arr[j],maxi[{i,j-1}]);
        }
    }
    // return solve(arr,0,n-1,maxi,dp);

    for(int i = n-1;i >= 0;i--){
        for(int j = i ;j < n;j++){
            if(i >= j) continue;
            int ans = INT_MAX;
            for(int k = i;k < j;k++){
                ans = min(ans,maxi[{i,k}] * maxi[{k+1,j}]+ dp[i][k] + dp[k+1][j]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][n-1];
}


int main(){
    // vector<int> arr = {6,2,4};
    vector<int> arr = {3,6,4,7,2,5};
    cout<<find(arr)<<endl;
    return 0;
}