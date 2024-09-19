// we have to find pivot of an given array.
#include<bits/stdc++.h>
using namespace std;

int pivot(int *arr,int l,int r){
    // cout<<l<<" "<<r<<endl;
    if(l >= r){
        return l;
    }
    int mid = l + (r - l) / 2;
    if(arr[0] <= arr[mid]){
        return pivot(arr,mid+1,r);
    }
    else{
        return pivot(arr,l,mid);
    }
}

int main(){
    // int arr[] = {1,1,1,1,1,2,1,1,1};
    int arr[] = {3,4,5,6,1,2};
    int size = sizeof(arr) / sizeof(int);
    cout<<pivot(arr,0,size-1);
    return 0;
}