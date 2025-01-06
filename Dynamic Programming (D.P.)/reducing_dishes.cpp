// in this question we have been given array which represent the satisfaction of the chef to a dish. and we have to return the max value of satisfaction by ording the dishes. using the given array. we can skip the dish also. return the max satisfaction in which the chef order.


#include<bits/stdc++.h>
using namespace std;

// using recursion
// int solve(vector<int> &arr,int i,int t,vector<vector<int>>& dp){
//     if(i == arr.size()) return 0;
//     if(dp[i][t] != -1) return dp[i][t];
//     cout<<"HElle"<<endl;
//     int ans = INT_MIN;
    
//     ans = solve(arr,i+1,t+1,dp) + (arr[i] * t);
//     ans = max(ans,solve(arr,i+1,t,dp));
//     dp[i][t] = ans;
//     return dp[i][t];
// }

// using double vector dp
// int find(vector<int> &arr){
//     sort(arr.begin(),arr.end());
//     int n = arr.size();
//     vector<int> next(n+1,0);
//     vector<int> cur(n+1,0);
//     for(int i = n-1;i >= 0;i--){
//         for(int t = i;t >= 0;t--){
//             int ans = INT_MIN;
    
//             ans = next[t+1] + (arr[i] * t);
//             ans = max(ans,next[t]);
//             cur[t] = ans;
//         }
//         next = cur;
//     }
//     return next[0];

// }

// using greedy approach
int find(vector<int> &satisfaction) {
    sort(satisfaction.rbegin(), satisfaction.rend());
        int ans = 0, coeff = 0, sum = 0;
        for (auto s : satisfaction) {
            sum += s;
            coeff = coeff + sum;
            if (ans > coeff) break;
            ans = coeff;
        }
        return ans;
}


int main(){
    vector<int> arr = {-1,-8,0,5,-9};
    cout<<find(arr)<<endl;
    return 0;
}