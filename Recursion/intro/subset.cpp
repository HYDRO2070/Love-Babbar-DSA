// we have been given array and we have to find power set. which mean set of all subset of array.

#include<bits/stdc++.h>
using namespace std;

void subset(vector<int> arr,int i,vector<int> op,vector<vector<int> >& ans){
    if(i == arr.size()){
        ans.push_back(op);
        return;
    }
    subset(arr,i+1,op,ans);
    op.push_back(arr[i]);
    subset(arr,i+1,op,ans);

}

int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    vector<vector<int> > ans;
    vector<int> op;
    // ans.push_back(op);
    // ans.push_back(arr);
    subset(arr,0,op,ans);
    sort(ans.begin(),ans.end());
    for(int i = 0;i < ans.size();i++){
        for(int j = 0;j < ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}