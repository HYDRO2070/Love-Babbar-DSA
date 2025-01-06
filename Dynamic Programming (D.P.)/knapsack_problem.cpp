// here we are going to study about the 2D Dp or 2 dimension dp through the knapsack problem here.
// problem description - a theif is caring a bag of maximum weight of {W} and there is an array with n item in it with i weight and v value. we have to find that in the give w weight bag the theif have to take maximum value. we have to help him.

#include<bits/stdc++.h>
using namespace std;

// using recursion
// void solve(int w,vector<int> &wt,vector<int> &val,int we,int sum,int i,int &ans){
//     if(we > w) return;
//     if(i >= wt.size()){
//         if(we <= w)
//         ans = max(ans,sum);
//         return;
//     }
//     cout<<"hello world"<<endl;
//     solve(w,wt,val,we+wt[i],sum+val[i],i+1,ans);
//     solve(w,wt,val,we,sum,i+1,ans);
// }

// using dp
// int solve(int w,vector<int> &wt,vector<int> &val,int i,vector<vector<int>> &dp){
//     if(i == wt.size()){
//         if(w-wt[i] >= 0){
//             return val[i];
//         }
//         return 0;
//     }
//     if(dp[i][w] != -1) return dp[i][w];
//     cout<<"hello world"<<endl;
//     int in = 0,ex = 0;
//     if(w-wt[i] >= 0)
//     in = val[i] + solve(w-wt[i],wt,val,i+1,dp);
//     ex = solve(w,wt,val,i+1,dp);
//     dp[i][w] = max(in,ex);
//     return dp[i][w];
// }

int find(int w,vector<int> &wt,vector<int> &val){
    // int ans = 0;
    // solve(w,wt,val,0,0,0,ans);
    int n = wt.size();
    // vector<vector<int>> dp(n,vector<int>(w+1,-1));
    // vector<int> pre(w+1,-1);
    vector<int> cur(w+1,-1);
    // return solve(w,wt,val,0,dp);

    for(int i = wt[0];i <= w;i++){
        if(wt[0] <= w)
        cur[i] = val[0];
        else
        cur[i] = 0;
    }
    // using 2d vector
    // for(int i = 1;i < n;i++){
    //     for(int j = 0;j <= w;j++){

    //         int inc = 0;
    //         if(wt[i] <= j)
    //             inc = val[i] + dp[i-1][j-wt[i]];
    //         int ex = 0 + dp[i-1][j];
    //         dp[i][j] = max(inc,ex);

    //     }
    // }
    // return dp[n-1][w];

    // using 2 vectors
    // for(int i = 1;i < n;i++){
    //     for(int j = 0;j <= w;j++){

    //         int inc = 0;
    //         if(wt[i] <= j)
    //             inc = val[i] + pre[j-wt[i]];
    //         int ex = 0 + pre[j];
    //         cur[j] = max(inc,ex);

    //     }
    //     pre = cur;
    // }
    // return pre[w];
    // using single vector
    for(int i = 1;i < n;i++){
        for(int j = w;j >= 0;j--){

            int inc = 0;
            if(wt[i] <= j)
                inc = val[i] + cur[j-wt[i]];
            int ex = 0 + cur[j];
            cur[j] = max(inc,ex);

        }
    }
    return cur[w];

}


int main(){
    int w = 5;
    vector<int> wt = {1,2,4,5};
    vector<int> val = {5,4,8,6};
    cout<<find(w,wt,val);
    return 0;
}