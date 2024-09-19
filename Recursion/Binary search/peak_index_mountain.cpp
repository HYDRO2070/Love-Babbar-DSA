// we have to find peak of the mountain

#include<bits/stdc++.h>
using namespace std;

int peakindex(int *arr,int l,int r){
    if(l >= r){
        return l;
    }
    int mid = l + (r - l) / 2;
    if(arr[mid] < arr[mid+1]){
        return peakindex(arr,mid+1,r);
    }
    else{
        return peakindex(arr,l,mid);
    }
}

int main(){
    int arr[] = {3,4,5,1,1,1};
    int size = sizeof(arr) / sizeof(int);
    cout<<peakindex(arr,0,size-1);
    return 0;
}