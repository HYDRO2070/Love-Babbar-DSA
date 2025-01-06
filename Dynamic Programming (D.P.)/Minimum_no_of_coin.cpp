// in this question we have been given the type's of coin and with using those we have to make an amount but there is an condition which is we have to return the minimum no of coin used to make that amount.
// there can be three condition : -
    // - the amount is zero
    // - the amount can be made using the give coin 
    // - return the ans.

#include<bits/stdc++.h>
using namespace std;

// recursive solution
// int solve(int *coin,int n){
//     // cout<<"Hello"<<endl;
//     if(n == 0) return 0;
//     if(n < 0) return -1;
//     int mini = INT_MAX;
//     for(int i = 0;i < 3;++i){
//         int temp = solve(coin,n-coin[i]);
//         if(temp != -1){
//             temp++;
//             mini = min(mini,temp);
//         }
//     }
//     return mini;
// }

// dp solution
// int solve(int *coin,vector<int> &dp,int n){
//     cout<<"Hello"<<endl;
//     if(n == 0) return 0;
//     if(n < 0) return -1;
//     if(dp[n] != -1) return dp[n];
//     dp[n] = INT_MAX;
//     for(int i = 0;i < 3;++i){
//         int temp = solve(coin,dp,n-coin[i]);
//         if(temp != -1){
//             temp++;
//             dp[n] = min(dp[n],temp);
//         }
//     }
//     return dp[n];
// }


// dp solution
int solve(int *coin,int n){
    vector<int> dp(n+1,INT_MAX);
    dp[0] = 0;
    for(int i = 1;i <= n;++i){
        for(int j = 0;j < 3;j++){
            if(i-coin[j] >= 0 && dp[i-coin[j]] != INT_MAX){
                dp[i] = min(dp[i], 1+ dp[i-coin[j]]);
            }
        }
    }
    return dp[n];
}


int main(){
    int coin[3] = {1,2,3};
    int n = 7;
    vector<int> dp(n+1,-1);
    // cout<<solve(coin,n);   for recursive call
    // cout<<solve(coin,dp,n);      for dp call
    cout<<solve(coin,n);
    return 0;
}