// we have to return maximum sum of non ajacent element which mean that we can't include ajacent element in the sum.

#include<bits/stdc++.h>
using namespace std;

// // recursive solution
// int solve(vector<int> &arr,int i){
//     cout<<"Hello"<<endl;
//     if(i >= arr.size()) return 0;
//     // int sum = 0;
//     // if included
//     int temp1 = arr[i] + solve(arr,i+2);
//     // not included
//     int temp2 = solve(arr,i+1);
//     return max(temp1,temp2);
// }




// // dp solution
// int solve(vector<int> &arr,vector<int> &dp,int i){
//     // cout<<"Hello"<<endl;
//     if(i >= arr.size()) return 0;
//     if(dp[i] != -1) return dp[i];
//     dp[i] =  max(arr[i] + solve(arr,dp,i+2),solve(arr,dp,i+1));
//     return dp[i];
// }

// dp tabulation solution
// int solve(vector<int> &arr){
//     int n = arr.size();
//     vector<int> dp(n+1,0);
//     dp[1] = arr[0];
//     // dp[1] = arr[1];
//     for(int i =2;i <= n;i++){
//         dp[i] = max(arr[i-1] + dp[i-2],dp[i-1]);
//     }
//     return dp[n];
// } 

int main(){
    vector<int> arr(4);
    vector<int> dp(4+1,-1);
    arr[0]= 9;
    arr[1]= 9;
    arr[2]= 8;
    arr[3]= 2;
    // cout<<solve(arr,0); recursive call
    // cout<<solve(arr,dp,0);   // dp call
    // cout<<solve(arr);   // dp tabulation call

    int first = 0;
    int second = arr[1];
    for(int i = 1;i < arr.size();++i){
        int third =  max(arr[i]+first,second);
        first = second;
        second = third;
    }
    cout<<second<<endl;


    return 0;
}