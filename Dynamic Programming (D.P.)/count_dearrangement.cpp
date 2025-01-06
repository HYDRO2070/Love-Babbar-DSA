// hat problem
// in this question we have ben give an interger value n and we have tto return the dearrangement count in return. dearrangement mean that in an array the element which are presen tat index should not be present at the same index.
// here an example [1,2,3] for this array an dearrange,ment can be [3,1,2] here all the number are present but not in there initial postion and we have to return the count of cimbination of that kind of array.

#include<bits/stdc++.h>
using namespace std;

// using recursion
// int solve(int n,vector<int> &dp){
//     cout<<"hello World"<<endl;
//     if(n == 1){
//         return 0;
//     }
//     if(n == 2){
//         return 1;
//     }
//     if(dp[n] != -1) return dp[n];
//     dp[n] = (n-1) * (solve(n-1,dp) + solve(n-2,dp));
//     return dp[n];
// }

int solve(int n){
    vector<int> dp(n+1,-1);
    // dp[1] = 0,dp[2] = 1;
    // for(int i = 3;i <= n;i++){
    //     dp[i] = (i-1)* (dp[i-1] + dp[i-2]);
    // }
    int a = 0,b = 1;
    for(int i = 3;i <= n;i++){
       int c = (i-1)* (a + b);
       a = b;
       b = c;
    }


    return b;
}
int main(){
    int n = 6;
    // vector<int> dp(n+1,-1);
    // cout<<solve(n,dp);
    cout<<solve(n);
    return 0;
}