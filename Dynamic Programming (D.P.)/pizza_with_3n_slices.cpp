// In this question we have been given the pizza and when i pick an pizza than alice will ick next clockwise slice and bob will pick nect anticlock wise slice. and we have to return the maximum slice sum that i can pick.

#include<bits/stdc++.h>
using namespace std;

// using recursion + memo
// int solve(int index,vector<int> &arr,int endindex,int n,vector<vector<int>> &dp){
//     if(n == 0 || index > endindex) return 0;
//     if(dp[index][n] != -1) return dp[index][n];
//     cout<<"helo"<<endl;
//     int inc = arr[index] + solve(index + 2,arr,endindex,n-1,dp);
//     int ex = solve(index + 1,arr,endindex,n,dp);
//     dp[index][n] = max(inc,ex);
//     return dp[index][n];
// }


int solve(vector<int> &arr,int s,int endindex){
    int k = arr.size();
    // vector<vector<int>> dp(k+2,vector<int>((k/3)+1,0));
    vector<int> curr((k/3)+1,0);
    vector<int> next((k/3)+1,0);
    vector<int> prev((k/3)+1,0);

    for(int index = s;index >= endindex;index--){
        for(int n = 1;n <= (k/3);n++){

            // int inc;
            // if(index+2 < k)
            int inc = arr[index] + next[n-1];
            int ex = curr[n];
            prev[n] = max(inc,ex);
        }
        next = curr;
        curr = prev;
    }
    return curr[k/3];
}

int find(vector<int> &arr){
    int k = arr.size();
    // vector<vector<int>> dp(k,vector<int>((k/3)+1,0));
    // return max(solve(0,arr,k-2,k/3,dp),solve(0,arr,k-1,k/3,dp));
    return max(solve(arr,k-1,1),solve(arr,k-2,0));
    

}

int main(){
    vector<int> arr = {1,2,3,4,5,6};
    // vector<int> arr = {9,5,1,7,8,4,4,5,5,8,7,7};
    cout<<find(arr)<<endl;
    return 0;
}