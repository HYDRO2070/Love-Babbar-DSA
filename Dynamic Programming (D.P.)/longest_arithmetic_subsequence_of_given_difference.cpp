// in this question we have been given a array with N interger with positive value in it. we have to find longest ap sequnce length in this array.

#include <bits/stdc++.h>
using namespace std;

// int solve(vector<int> &arr, int index, int d, int last)
// {
//     if (index >= arr.size())
//         return 0;
//     // if ((last + d) != arr[index])
//     //     return 0;
//     cout << "hello" << endl;
//     int ans = 0;

//     for (int i = index; i < arr.size(); i++)
//     {   
//         if(last + d == arr[index])
//         ans = max(ans, 1 + solve(arr, i, d, arr[index]));
//     }
//     return ans;
// }

// int find(vector<int> &arr, int D)
// {
//     // return solve(arr,D,0);
//     int n = arr.size();
//     int ans = 0;
//     for (int i = 0;i < n-1; i++)
//     {
//         ans = max(ans, 1 + solve(arr,i+1,D,arr[i]));
//     }
//     return ans;
// }



int find(vector<int> &arr, int D){
    unordered_map<int,int>dp;
    int ans = 0;
    int n = arr.size();
    for(int i = 0;i < n;i++){
        int temp = arr[i] - D;
        int tempans = 0;
        if(dp.count(temp)) tempans = dp[temp];

        dp[arr[i]] = 1 + tempans;
        ans = max(ans,dp[arr[i]]);
    }
    return ans;
}



int main()
{
    // vector<int> arr = {1, 7, 10, 13, 14, 19};
    // vector<int> arr = {1,2,3,4,5,6};
    vector<int> arr = {1,5,7,8,5,3,4,2,1};
    // int D = 6;
    // int D = 1;
    int D = -2;
    cout << find(arr, D) << endl;
    return 0;
}