// we have been give an array and we have to return the size of the longest increisng subsequnce which mean the subarray must must be in order as they were in the main array and in incresing order.

#include<bits/stdc++.h>
using namespace std;

// using recursion
// int solve(vector<int> &arr,int previous,int index,vector<int> &dp){
//     if(index >= arr.size()) return 0;
//     if(dp[index] != -1) return dp[index];
//     cout<<"helo"<<endl;
//     int ans = INT_MIN;

//     for(int i = index;i < arr.size();i++){
//         if(previous <= arr[i])
//             ans = max(solve(arr,arr[i],i+1,dp) + 1,ans);
//     }
//     dp[index] = (ans == INT_MIN) ? 0 : ans;
//     return dp[index];
// }

// int find(vector<int> &arr){
    // int ans = INT_MIN;
    // int n = arr.size();
    // vector<int> dp(n,-1);
    // for(int i = 0;i < n;i++){
    //     // if(dp[i] == -1)
    //     ans = max(ans,solve(arr,arr[i],i+1,dp) + 1);
    //     // else ans  = max(ans,dp[i]+1);
    // }
    // return ans;
    // return solve(arr,arr[0],1,dp)+1;

// }


// using second method

// int solve(vector<int> &arr,int curr,int prev,vector<vector<int>> &dp){
//     if(curr == arr.size()) return 0;
//     if(dp[curr][prev+1] != -1) return dp[curr][prev+1];
//     cout<<"hell0o"<<endl;
//     int take = 0;
//     if(prev == -1 || arr[curr] > arr[prev])
//         take = 1 + solve(arr,curr+1,curr,dp);
//     int nottaken = 0;
//     nottaken = 0 + solve(arr,curr+1,prev,dp);
//     dp[curr][prev+1] = max(take,nottaken);
//     return dp[curr][prev+1];
// }

// int find(vector<int> &arr){
    // return solve(arr,0,-1);
    // int n = arr.size();
    // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    // return solve(arr,0,-1,dp);
    // for(int curr = n-1;curr >= 0;curr--){
    //     for(int prev = curr-1;prev >= -1;prev--){

    //         int take = 0;
    //         if(prev == -1 || arr[curr] > arr[prev])
    //             take = 1 + dp[curr+1][curr+1];
    //         int nottaken = 0;
    //         nottaken = 0 + dp[curr+1][prev+1];
    //         dp[curr][prev+1] = max(take,nottaken);
    //     }
    // }


//     vector<int> nextarr(n+1,0);
//     vector<int> currarr(n+1,0);
//     for(int curr = n-1;curr >= 0;curr--){
//         for(int prev = curr-1;prev >= -1;prev--){

//             int take = 0;
//             if(prev == -1 || arr[curr] > arr[prev])
//                 take = 1 + nextarr[curr+1];
//             int nottaken = 0;
//             nottaken = 0 + nextarr[prev+1];
//             currarr[prev+1] = max(take,nottaken);
//         }
//         nextarr = currarr;
//     }

//     return nextarr[0];
// }

void print(vector<int> &value){
    for(int num : value){
        cout<<num<<" ";
    }
    cout<<endl;
}

void binary_S(vector<int> &value,int num){
    int left = 0;
    int right = value.size()-1;
    int mid = left + (right - left) / 2;
    // cout<<num<<endl;
    while(left < right){
        // cout<<"hello"<<endl;
        if(value[mid] < num){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
        mid = left + (right - left) / 2;
    }
    value[left] = num;
    // cout<<left<<" "<<mid<<" "<<right<<endl;
}

// dp with binary search
int find(vector<int> &arr){
    int n = arr.size();
    // sort(arr.begin(),arr.end());
    vector<int> value;
    value.push_back(arr[0]);
    for(int i = 1;i < n;i++){
        if(arr[i] > value.back()) value.push_back(arr[i]);
        else{
            // cout<<"---"<<endl;
            // binary_S(value,arr[i]);
            int index = lower_bound(value.begin(),value.end(),arr[i]) - value.begin();
            value[index] = arr[i];
        }
    // print(value);
    }

    return value.size();
}



int main(){
    vector<int> arr = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
    // vector<int> arr = {5,8,3,7,9,1};
    cout<<find(arr)<<endl;
    return 0;
}