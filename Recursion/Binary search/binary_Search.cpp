// implement binary search using recursion.

#include<bits/stdc++.h>
using namespace std;

bool binary_search(int *arr,int l,int r,int t){
    cout<<"he he"<<endl;
    if(l > r){
        return false;
    }
    int mid = l +(r - l) /2;
    if(arr[mid] == t){
        return true;
    }
    else if(arr[mid] < t){
        return binary_search(arr,mid+1,r,t);
    }
    else{
        return binary_search(arr,l,mid-1,t);

    }
}

int main(){
    int arr[9] = {1,2,3,4,5,6,7,8,9};
    int t = 50;
    int size = 9;
    cout<<binary_search(arr,0,size-1,t);
    return 0;
}