// in this question we have been given N the no of the element in the array and an arraywith value and an target element. we have to find the no of combinatiopn of element form the array so that the sum is equal to the target. return it.

#include<bits/stdc++.h>
using namespace std;

// int solve(vector<int> &arr,int t,vector<int> &dp){
//     if(t == 0) return 1;
//     if(t < 0) return 0;
//     if(dp[t] != -1) return dp[t];
//     int n = arr.size();
//     int ans = 0;
//     cout<<"hellow"<<endl;
//     for(int j = 0;j < n;j++){
//         if(t-arr[j] >= 0)
//         ans += solve(arr,t-arr[j],dp);

//     }
//     dp[t] = ans;
//     return dp[t];
// }

int find(vector<int> &arr,int t){
    vector<int> dp(t+1,-1);
    // return solve(arr,t,dp);
    dp[0] = 1;
    int n = arr.size();

    for(int i = 1;i <= t;i++){
        int ans = 0;
        for(int j = 0;j < n;j++){
            if(i-arr[j] >= 0)
            ans += dp[i-arr[j]];

        }
        dp[i] = ans;
    }
    return dp[t];
}


int main(){
    vector<int> arr = {1,2,5};
    int target = 5;
    cout<<find(arr,target);
    return 0;
}