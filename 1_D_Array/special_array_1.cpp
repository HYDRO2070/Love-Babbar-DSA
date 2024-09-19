// if two odd or even number are adjacency then return false otherwise return true.

#include<bits/stdc++.h>
using namespace std;

bool find(vector<int> arr,int i){
    if(i >= arr.size()-1){
        return true;
    }
    if((arr[i]&1 && arr[i+1]&1) || (!(arr[i]&1) && !(arr[i+1]&1))){
        return false;
    }
    return find(arr,i+1);
}

int main(){
    vector<int> arr;
    arr.push_back(4);
    // arr.push_back(3);
    arr.push_back(1);
    arr.push_back(6);
    cout<<find(arr,0);
    return 0;
}