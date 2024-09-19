#include<bits/stdc++.h>
using namespace std;

void print(vector<int> arr){
    for(int i = 0;i < arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void reverse(vector<int> &ans){
    for(int i = 0;i < ans.size()/2;i++){
        swap(ans[i],ans[ans.size()-1-i]);
    }
}

// vector<int> next(vector<int> arr){
//     int size = arr.size();
//     vector<int> ans;
//     int s = arr[size-1];
//     ans.push_back(-1);
//     for(int i = size-2;i>=0;i--){
//         if(arr[i] > s){
//             ans.push_back(s);
//         }
//         else{
//             ans.push_back(-1);
//         }
//         s = min(s,arr[i]);
//     }
//     reverse(ans);
//     return ans;
// }
vector<int> next(vector<int> arr){
    stack<int> s;
    vector<int> ans;
    s.push(-1);
    
    int n = arr.size();
    for(int i = n-1;i >= 0;i--){
        while(s.top() != -1 && arr[s.top()] > arr[i]){
            s.pop();
        }
        ans.push_back(s.top());
        s.push(i);
    }
    reverse(ans);
    return ans;
}

int main(){
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(3);
    print(arr);
    print(next(arr));

    return 0;
}