// we have to find digit diffence and sum with it and return it.okay

#include<bits/stdc++.h>
using namespace std;

int find(vector<int> arr,int i){
    // cout<<"heloo"<<endl;
    if(i >= arr.size()-1){
        return 0;
    }
    int ans = 0;
    for(int j = i+1;j < arr.size();j++){
        // cout<<ans<<endl;
        if(arr[i] != arr[j]){
            int temp = arr[j];
            int temp1 = arr[i];
            while(temp1){
                ans += abs((temp1%10) - (temp%10));
                temp1 /= 10;
                temp /= 10;
            }
        }
    }
    return ans + find(arr,i+1);
}

int main(){
    vector<int> arr;
    arr.push_back(10);
    arr.push_back(10);
    arr.push_back(10);
    arr.push_back(10);
    cout<<find(arr,0);
    return 0;
}