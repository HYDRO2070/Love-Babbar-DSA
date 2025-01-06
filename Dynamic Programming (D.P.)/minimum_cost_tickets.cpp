// we have been given integer which represent days from an year. and we have cost of ticket which have three varity 1day,7day and 30 day with different cost, so our task is to find the minimum cost for ticket so that we can travel on the day which are provides.

#include<bits/stdc++.h>
using namespace std;

// using recursion
// int solve(vector<int> &day,vector<int> &cost,int d,int i,int sum){
//     cout<<"hellor"<<endl;
//     if(i == day.size()){
//         return sum;
//     }
//     if(d-1 >= day[i])
//     return solve(day,cost,d,i+1,sum);

//     int o = solve(day,cost,d+1,i+1,sum+cost[0]);
//     int t = solve(day,cost,d+7,i+1,sum+cost[1]);
//     int e = solve(day,cost,d+30,i+1,sum+cost[2]);
//     return min(o,min(t,e));
// }
// void print(vector<int> &dp){
//     for(auto num : dp){
//         cout<<num<<" ";
//     }
//     cout<<endl;
// }

// using another menthod
// int solve(int n,vector<int> &day,vector<int> &cost,int i,vector<int> &dp){
//     // print(dp);
//     cout<<"Hello"<<endl;
//     if(i >= n){
//         return 0;
//     }
//     if(dp[i] != - 1) return dp[i];

//     int o = cost[0] + solve(n,day,cost,i+1,dp);

//     int j;

//     for(j = i;j < n && day[j] < day[i]+7;j++);

//     int t = cost[1] + solve(n,day,cost,j,dp);

//     for(j = i;j < n && day[j] < day[i]+30;j++);

//     int e = cost[2] + solve(n,day,cost,j,dp);
//     dp[i] = min(o,min(t,e));
//     return dp[i];
// }


// int find(int n,vector<int> &day,vector<int> &cost){
//     vector<int> dp(n+1,INT_MAX);
//     // return solve(day,cost,day[0],0,0);
//     // return solve(n,day,cost,0,dp);


//     dp[n] = 0;

//     for(int i = n-1;i >= 0;i--){
//         int o = cost[0] + dp[i+1];

//         int j;

//         for(j = i;j < n && day[j] < day[i]+7;j++);

//         int t = cost[1] + dp[j];

//         for(j = i;j < n && day[j] < day[i]+30;j++);

//         int e = cost[2] + dp[j];
//         dp[i] = min(o,min(t,e));
//     }
//     return dp[0];
// }

// space optimizing method
int find(int n,vector<int> &day,vector<int> &cost){
    int ans = 0;
    queue<pair<int,int>> m;
    queue<pair<int,int>> w;

    for(int d : day){
        while(!m.empty() && m.front().first+30 <= d) m.pop();
        while(!w.empty() && w.front().first+7 <= d) w.pop();

        m.push(make_pair(d,ans+cost[2]));
        w.push(make_pair(d,ans+cost[1]));

        ans = min(ans+cost[0],min(m.front().second,w.front().second));
    }
    return ans;
}

int main(){
    int n = 7;
    vector<int> day = {1,3,4,5,7,8,10};
    vector<int> cost = {2,7,20};
    cout<<find(n,day,cost);
    return 0;
}