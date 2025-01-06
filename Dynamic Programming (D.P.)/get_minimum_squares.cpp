// in this question we have been given N which is a number and we have to return the smallest number square to get the N.
// example - N = 100 
// 10*10 = 100  but in this we only have to find single num square so this is answer.
// 5^2 + 5^2 + 5^2+ 5^2 = 100
// .....


#include<bits/stdc++.h>
#include<math.h>
using namespace std;

// int solve(int n,vector<int> &dp){
//     if(n == 0) return 0;
//     if(n < 0) return 0;
//     if(dp[n] != -1) return dp[n];
//     int ans = INT_MAX;
//     int l = sqrt(n);
//     // cout<<n<<endl;
//     for(int i = 1;i <= l;i++){
//         ans = min(solve(n-(i*i),dp)+1,ans);
//     }
//     dp[n] = ans;
//     return dp[n];

// }


int find(int n){
    vector<int> dp(n+1,-1);
    // return solve(n,dp);
    dp[0] = 0;

    for(int i = 1;i <= n;i++){
        int ans = INT_MAX;
        int l = sqrt(i);
        for(int j = 1;j <= l;j++){
            if(i-(j*j) >= 0)
            ans = min(dp[i-(j*j)]+1,ans);
        }
        dp[i] = ans;
    }
    return dp[n];
}


int main(){
    int n = 100;
    cout<<find(n);

    return 0;
}