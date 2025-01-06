// in this question there is an rober who will rob house's but there is an condition that that rober cant rob two adjacent houses in a row. so we have to return the maximum money he can rob applying the condtion.

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr){
    int n = arr.size();
    int prev2 = 0;
    int prev1 = arr[0];

    for(int i = 1;i < n;i++){
        int in = prev2 + arr[i];
        int ex = prev1 + 0;
        int ans = max(in,ex);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}


int main(){
    vector<int> arr = {5,2,3,5};
    vector<int> first,second;

    for(int i = 0;i < arr.size();i++){
        if(i != 0)
        second.push_back(arr[i]);
        if(i != arr.size()-1)
        first.push_back(arr[i]);
    }
    cout<<max(solve(first),solve(second))<<endl;

    return 0;
}