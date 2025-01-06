// we have been given two array and we can swap ith value from both array. and we have to return minimum swap required to make both array strickly incresing order. meaning No duplicate number + in incresing order.


#include<bits/stdc++.h>
using namespace std;

// int solve(vector<int> &arr1,vector<int> &arr2,int index,bool swaped){
//     if(index == arr1.size()) return 0;
//     cout<<"hello"<<endl;
//     int ans = 0;

//     if(swaped){
//         if(arr1[index] > arr2[index-1] && arr2[index] > arr1[index-1]){
//             ans += solve(arr1,arr2,index+1,false);
//         }
//         else{
//             ans += 1 + solve(arr1,arr2,index+1,true);
//         }
//     }
//     else{
//         if(arr1[index] > arr1[index-1] && arr2[index] > arr2[index-1]){
//             ans += solve(arr1,arr2,index+1,false);
//         }
//         else{
//             ans += 1 + solve(arr1,arr2,index+1,true);
//         }
//     }
//     return ans;
// }

// int solve(vector<int> &arr1,vector<int> &arr2,int index,bool swaped,vector<vector<int>> &dp){
//     if(index == arr1.size()) return 0;
//     if(dp[index][swaped] != -1) return dp[index][swaped];
//     cout<<"hello"<<endl;
//     int ans = INT_MAX;
//     int l1 = arr1[index-1];
//     int l2 = arr2[index-1];

//     if(swaped) swap(l1,l2);

//     if(arr1[index] > l1 && arr2[index] > l2)
//         ans = solve(arr1,arr2,index+1,false,dp);

//     if(arr1[index] > l2 && arr2[index] > l1)
//         ans = min(ans,1 + solve(arr1,arr2,index+1,true,dp));
//     dp[index][swaped] = ans;
//     return dp[index][swaped];
// }

int find(vector<int> &arr1,vector<int> &arr2){
    int n = arr1.size();
    // arr1.insert(arr1.begin(),-1);
    // arr2.insert(arr2.begin(),-1);
    // vector<vector<int>> dp(n+1,vector<int>(2,0));
    // return solve(arr1,arr2,1,false,dp);


    // for(int index = n-1;index >= 1;index--){
    //     for(int swaped = 1;swaped >= 0;swaped--){
    //         int ans = INT_MAX;
    //         int l1 = arr1[index-1];
    //         int l2 = arr2[index-1];

    //         if(swaped) swap(l1,l2);

    //         if(arr1[index] > l1 && arr2[index] > l2)
    //             ans = dp[index+1][0];

    //         if(arr1[index] > l2 && arr2[index] > l1)
    //             ans = min(ans,1 + dp[index+1][1]);
    //         dp[index][swaped] = ans;
    //     }
    // }
    // return dp[1][0];


    pair<int,int> curr = make_pair(0,0);
    pair<int,int> next = make_pair(0,0);
    for(int index = n-1;index >= 1;index--){
        for(int swaped = 1;swaped >= 0;swaped--){
            int ans = INT_MAX;
            int l1 = arr1[index-1];
            int l2 = arr2[index-1];

            if(swaped) swap(l1,l2);

            if(arr1[index] > l1 && arr2[index] > l2)
                ans = next.first;

            if(arr1[index] > l2 && arr2[index] > l1)
                ans = min(ans,1 + next.second);
            
            if(swaped == 1) curr.second = ans;
            else curr.first = ans;
            
        }
        next = curr;
    }
    return next.first;
}


int main(){
    vector<int> arr1 = {1,3,5,4};
    vector<int> arr2 = {1,2,3,7};
    // vector<int> arr1 = {0,3,5,8,9};
    // vector<int> arr2 = {2,1,4,6,9};
    cout<<find(arr1,arr2)<<endl;
    return 0;
}