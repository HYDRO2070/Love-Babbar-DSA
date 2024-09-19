#include<bits/stdc++.h>
using namespace std;

int count(int *arr,int size){
    unordered_map<int,int> m;
    for(int i = 0;i < size;i++){
        m[arr[i]]++;
    }
    int maxi = arr[0];
    for(auto i : m){
        if(m[maxi] < m[i.first]){
            maxi = i.first;
        }
    }
    return maxi;
}

int main(){
    int arr[13] = {3,5,8,4,6,8,4,2,5,6,8,4,4};
    cout<<count(arr,13);
    return 0;
}