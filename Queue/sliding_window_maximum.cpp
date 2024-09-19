#include<bits/stdc++.h>
using namespace std;

void print(vector<int> arr){
    for(int i = 0;i < arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> solve(int *arr,int n,int k){
    deque<int> maxi;
    vector<int> ans;
    for(int i = 0;i < k;i++){
        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
        maxi.pop_back();
        maxi.push_back(i);
    }
    for(int i = k;i<n;i++){
        ans.push_back(arr[maxi.front()]);

        while(!maxi.empty() && i-maxi.front() >= k)
        maxi.pop_front();

        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
        maxi.pop_back();
        maxi.push_back(i);
    }
    ans.push_back(arr[maxi.front()]);
    return ans;
}

int main(){
    int arr[8] = {1,3,-1,-3,5,3,6,7};
    print(solve(arr,8,3));
    return 0;
}