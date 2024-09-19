// AS the question name suggest. we have to find subset of a array and xor of them and return sum of all xor.

#include<bits/stdc++.h>
using namespace std;

// void subset(vector<int> arr,int i,vector<int> op,vector<vector<int> >& ans){
//     // cout<<"HELLOE"<<endl;
//     if(i >= arr.size()){
//         if(op.size() > 0){
//             for(int i = 0;i < op.size();i++){
//                 cout<<arr[i]<<" ";
//             }
//             cout<<endl;
//             ans.push_back(op);
//         }
//         return;
//     }
//     subset(arr,i+1,op,ans);
//     op.push_back(arr[i]);
//     subset(arr,i+1,op,ans);
// }
int subset(vector<int> arr,int i,int x){
    if(i >= arr.size()){
        return x;
    }
    int a = subset(arr,i+1,x);
    int b = subset(arr,i+1,x ^ arr[i]);
    // op.push_back(arr[i]);

    return a+b;
}

int main(){
    vector<int> arr;
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);
    arr.push_back(8);
    // arr.push_back(3);
    // vector<int> op;
    int a = 0;
    // vector<vector<int> > ans;
    cout<<subset(arr,0,a);
    // for(int i = 0;i < ans.size();i++){
    //     for(int j = 0; j < ans[i].size();j++){
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}