// we have to use binarysearch and find the allocation of an element but the arrays is rotated.

#include<bits/stdc++.h>
using namespace std;

int binarysearch(int *arr,int l,int r,int t){
    if(l > r){
        return -1;
    }
    int mid = l + (r - l) / 2;
    if(arr[mid] == t){
        return mid;
    }
    else if(arr[mid] > t){
        return binarysearch(arr,l,mid-1,t);
    }
    else{
        return binarysearch(arr,mid+1,r,t);
    }
}

int pivot(int *arr,int l,int r){
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

int search(int *arr,int size,int t){
    int p = pivot(arr,0,size-1);
    return (arr[p] <= t && t >= arr[size-1]) ? binarysearch(arr,p,size-1,t) : binarysearch(arr,0,p,t);
}


int main(){
    int arr[2] = {1,13};
    int target = 13;
    int size = 2;
    cout<<search(arr,size,target);
    return 0;
}