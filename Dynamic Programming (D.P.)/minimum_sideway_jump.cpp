// in this question there are three lane and a frog and we have to return min sidejump so that frog can react the end which is n. there are obstakel in the path so we have to avoid them. and sidejump value will increse if we change lane not in the same lane.
// at the starting the frong is at the middle lane. which will be 2th.

#include <bits/stdc++.h>
using namespace std;

// int solve(vector<int> &ob, int op, int lane, vector<vector<int>> &dp)
// {
//     if (op == ob.size() - 1)
//         return 0;
//     if (dp[lane - 1][op] != INT_MAX)
//         return dp[lane - 1][op];
//     int ans = INT_MAX;
//     // cout << op << " " << lane << endl;

//     if (ob[op + 1] != lane)
//     {
//         cout << "straight" << endl;
//         ans = min(ans, solve(ob, op + 1, lane, dp));
//     }
//     else if (lane >= 2 && ob[op] != lane - 1)
//     {
//         cout << "up" << endl;
//         ans = min(ans, 1 + solve(ob, op, lane - 1, dp));
//     }
//     else if (lane == 3 && ob[op] != lane - 2)
//     {
//         cout << "up up" << endl;
//         ans = min(ans, 1 + solve(ob, op, lane - 2, dp));
//     }
//     else if (lane <= 2 && lane >= 1 && ob[op] != lane + 1)
//     {
//         cout << "down" << endl;
//         ans = min(ans, 1 + solve(ob, op, lane + 1, dp));
//     }
//     else
//     {
//         cout << "down down" << endl;
//         ans = min(ans, 1 + solve(ob, op, lane + 2, dp));
//     }
//     // cout<<ans<<endl;
//     dp[lane - 1][op] = ans;
//     return dp[lane - 1][op];
// }


int solve(vector<int> &ob,int po,int lane,vector<vector<int>> &dp){
    if(po == ob.size()-1) return 0;
    if(dp[lane-1][po] != -1) return dp[lane-1][po];
    cout<<"Hello"<<endl;


    if(ob[po+1] != lane){
        dp[lane-1][po] = solve(ob,po+1,lane,dp);
        return dp[lane-1][po];
    }
    else{
        int ans = INT_MAX;

        for(int i = 1;i <= 3;i++){
            if(i != lane && ob[po] != i)
                ans = min(ans,1 + solve(ob,po,i,dp));
        }
        dp[lane-1][po] = ans;
        return dp[lane-1][po];
    }
}



// int find(vector<int> &ob)
// {
//     int n = ob.size();
//     // vector<vector<int>> dp(4, vector<int>(n, 1e9));
//     // return solve(ob, 0, 2,dp);

//     // dp[0][n-1] = 0;
//     // dp[1][n-1] = 0;
//     // dp[2][n-1] = 0;

//     for(int po = n-2;po >= 0;po--){
//         for(int lane = 1;lane <= 3;lane++){
//             if(ob[po+1] != lane){
//                 dp[lane][po] = dp[lane][po+1];
//             }
//             else{
//                 int ans = 1e9;

//                 for(int i = 1;i <= 3;i++){
//                     if(i != lane && ob[po] != i)
//                         ans = min(ans,1 + dp[i][po+1]);
//                 }
//                 dp[lane][po] = ans;
//             }
//         }
//     }
//     return min(dp[1][0]+1,min(dp[2][0],1+dp[3][0]));
// }
int find(vector<int> &ob)
{
    int n = ob.size();
    vector<vector<int>> dp(4, vector<int>(n, 1e9));
    // return solve(ob, 0, 2,dp);

    vector<int> next(4,0);
    vector<int> cur(4,1e9);


    for(int po = n-2;po >= 0;po--){
        for(int lane = 1;lane <= 3;lane++){
            if(ob[po+1] != lane){
                cur[lane] = next[lane];
            }
            else{
                int ans = 1e9;

                for(int i = 1;i <= 3;i++){
                    if(i != lane && ob[po] != i)
                        ans = min(ans,1 + next[i]);
                }
                cur[lane] = ans;
            }
        }
        next = cur;
    }
    return min(next[1]+1,min(next[2],1+next[3]));
}

int main()
{
    vector<int> ob = {0, 1, 2, 3, 1};
    cout << find(ob) << endl;
    return 0;
}