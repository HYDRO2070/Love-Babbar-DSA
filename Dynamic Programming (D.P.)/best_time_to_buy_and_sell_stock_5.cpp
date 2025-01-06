// this question is same we can buy as many stock as we wish but in this question we have to pay an transaction fees after an buy and sell. so now return the maximum profit.

#include <bits/stdc++.h>
using namespace std;

int find(vector<int> &arr, int fee)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int ans = 0;

            if (buy)
                ans = dp[index + 1][0] - arr[index];
            else
                ans = max(ans, arr[index] + dp[index + 1][1] - fee);

            ans = max(ans, dp[index + 1][buy]);
            dp[index][buy] = ans;
        }
    }
    return dp[0][1];
}

int main()
{
    // vector<int> arr= {1,3,7,5,10,3};
    vector<int> arr = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    cout << find(arr, fee) << endl;
    return 0;
}