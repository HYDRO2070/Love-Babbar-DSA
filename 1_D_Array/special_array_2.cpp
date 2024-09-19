// same as before. but we have to check according to given 2d index.

#include<bits/stdc++.h>
using namespace std;

bool find(vector<int> arr,int i,int l){
    if(i == l){
        return true;
    }
    if((arr[i]&1 && arr[i+1]&1) || (!(arr[i]&1) && !(arr[i+1]&1))){
        return false;
    }
    return find(arr,i+1,l);
}

int main(){
    vector<int> arr;
    arr.push_back(4);
    arr.push_back(3);
    arr.push_back(1);
    // arr.push_back(2);
    arr.push_back(6);
    // vector<bool> ans;
    int t[2][2] = {{0,2},{2,3}};
    for(int i = 0;i<2;i++){
        cout<<find(arr,t[i][0],t[i][1])<<endl;
    }

    return 0;
}