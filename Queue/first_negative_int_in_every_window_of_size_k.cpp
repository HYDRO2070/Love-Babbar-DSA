#include<bits/stdc++.h>
using namespace std;

void print(vector<int> arr){
    for(int i = 0;i < arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> find(vector<int> arr,int k){
    deque<int> q;
    vector<int> ans;
    // for(int i = 0;i < k;i++){
    //     if(arr[i] < 0){
    //         ans.push_back(arr[i]);
    //     }
    // }
    for(int i = 0;i <= arr.size()-k;i++){
        int flag = 0;
        for(int j = i;j < i+k;j++){
            if(arr[j] < 0){
                flag = 1;
                ans.push_back(arr[j]);
            }
        }
        if(flag != 1) ans.push_back(0);
    }
    return ans;
}

int main(){
    vector<int> arr;
    arr.push_back(-8);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(-6);
    arr.push_back(10);
    print(arr);
    print(find(arr,2));
    return 0;
}