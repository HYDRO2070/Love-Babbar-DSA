// Given an array arr[] of size N,check if it can be partitioned into two parts such that the  sum of elements in both parts in the same.

#include<bits/stdc++.h>
using namespace std;

// bool solve(vector<int> &arr,int t,int index,vector<vector<int>> &dp){
//     if(t < 0) return 0;
//     if(t == 0) return true;
//     if(index >= arr.size()) return false;
//     if(dp[t][index] != -1) return dp[t][index];
//     cout<<"hello"<<endl;
//     bool take = solve(arr,t-arr[index],index+1,dp);
//     bool nottake = solve(arr,t,index+1,dp);
//     dp[t][index]= (take || nottake);
//     return dp[t][index];
// }

bool find(vector<int> &arr){
    int n = arr.size();
    int sum = 0;
    for(int num : arr) sum += num;
    if(sum & 1) return false;
    int ta = (sum/2);
    // vector<vector<int>> dp(ta+1,vector<int>(n,-1));
    // return solve(arr,sum/2,0,dp);

    // for(int i = 0;i < n;i++) dp[0][i] = 1;

    // for(int index = n-1;index >= 0;index--){
    //     for(int t = 1;t <= ta;t++){
    //         bool take = false;
    //         if(t-arr[index] > 0)
    //         dp[t-arr[index]][index+1];
    //         bool nottake = dp[t][index+1];
    //         dp[t][index]= (take || nottake);
    //     }
    // }
    // return dp[ta][0];

    vector<int> curr(n+1,0);
    vector<int> next(n+1,0);
    curr[0] = 1;
    next[0] = 1;

    for(int index = n-1;index >= 0;index--){
        for(int t = 1;t <= ta;t++){
            bool take = false;
            if(t-arr[index] >= 0)
            next[t-arr[index]];
            bool nottake = next[t];
            curr[t]= (take || nottake);
        }
        next = curr;
    }
    return next[0];
}

int main(){
    vector<int> arr = {1,5,11,5};
    // vector<int> arr = {1,3,5};
    cout<<find(arr)<<endl;
    return 0;
}