// as the name suggest in this we have been given an array of stock and we have to determine when to buy and then sell it to gain maximum profit in it.

#include<bits/stdc++.h>
using namespace std;

int find(vector<int> &arr){
    int n = arr.size();
    int mini = arr[0];
    int ans = 0;
    for(int i = 1;i < n;i++){
        ans = max(ans,arr[i]-mini);
        mini = min(mini,arr[i]);
    }
    return ans;
}


int main(){
    vector<int> arr = {7,1,5,3,6,4};    
    cout<<find(arr)<<endl;
    return 0;
}