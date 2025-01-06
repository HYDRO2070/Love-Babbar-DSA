// in this question we have been given a array with N interger with positive value in it. we have to find longest ap sequnce length in this array.
// Ex -> a+ a*d+ a82d+ .....
// where d is the common difference

#include<bits/stdc++.h>
using namespace std;

// int solve(vector<int> &arr,int index,int d,int last,unordered_map<int,int> dp[]){
//     if(index >= arr.size()) return 0;
//     if(d != 0 && (last + d) != arr[index]) return 0;
//     if(dp[index].count(d)) return dp[index][d];
//     cout<<"hello"<<endl;
//     int ans = INT_MIN;

//     for(int i = index;i < arr.size();i++){
//         ans = max(ans,1 + solve(arr,i,arr[index]-last,arr[index],dp));
//     }
//     dp[index][d] = ans;
//     return dp[index][d];
// }
//     // using recursion + memo
// int find(vector<int> &arr){
//     int ans = INT_MIN;
//     int n = arr.size();
//     unordered_map<int,int> dp[n+1];

//     for(int i = 0;i < n;i++){
//         ans = max(ans,1 + solve(arr,i+1,0,arr[i],dp));
//     }
//     return ans;
// }

// using tabulation method
// int find(vector<int> &arr){
//     int n = arr.size();
//     if(n <= 2) return n;
//     int ans = 0;
//     unordered_map<int,int> dp[n+1];

//     for(int i = 1;i <n;i++){
//         for(int j = 0;j < i;j++){
//             int d = arr[i]-arr[j];
//             int cnt = 1;
//             if(dp[j].count(d)) cnt = dp[j][d];
//             dp[i][d] = 1 + cnt;
//             ans = max(ans,dp[i][d]);
//         }
//     }
//     return ans;
// }


int main(){
    // vector<int> arr = {1,7,10,13,14,19};
    // vector<int> arr = {1,5,7,8,5,3,4,2,1};
    // vector<int> arr = {2,4,6,8,10};
    cout<<find(arr)<<endl;
    return 0;
}