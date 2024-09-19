// in this we have been given an array with positive integers and we have to return an array or vector which lets the count of distict int till ith element.
// input - [1,1,1,1,2,1]
// output - [1,1,1,1,2,2]

#include<bits/stdc++.h>
using namespace std;
void print(vector<int> arr){
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> prefix(vector<int> arr){
    set<int> temp;
    vector<int> ans;
    for(int i = 0;i < arr.size();i++){
        temp.insert(arr[i]);
        ans.push_back(temp.size());
    }
    // for(int i = 0;i<ans.size();i++){
    //     cout<<ans[i]<<" ";
    // }
    // cout<<endl;
    return ans;
}

int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(1);
    print(arr);
    vector<int> ans = prefix(arr);
    print(ans);
    return 0;
}