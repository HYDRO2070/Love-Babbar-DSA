// combination of array. and i won't say anymore.

#include<bits/stdc++.h>
using namespace std;

void find(vector<int> arr,int i,vector<vector<int> >& ans){
    if(i >= arr.size()){
        ans.push_back(arr);
        return;
    }
    // find(s,i+1,a,ans);
    for(int j = i;j < arr.size();j++){
        
        swap(arr[j],arr[i]);
        find(arr,i+1,ans);
        swap(arr[j],arr[i]);
    }
}

int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    // string a = "";
    vector<vector<int> > ans;
    find(arr,0,ans);
    for(int i = 0;i < ans.size();i++){
        for(int j = 0;j < ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}