// in this we have been an array with ith index pages of a book. and we have to divide it according to k which is given. so that the difference is the minimum.

#include<bits/stdc++.h>
using namespace std;

int sum(int *arr,int size){
    if(size == 0){
        return 0;
    }
    return arr[0] + sum(arr+1,size-1);
}

bool ispossible(int *arr,int s,int n,int l){
    int st = 1;
    int pc = 0;
    for(int i = 0;i < s;i++){
        if(pc + arr[i] <= l){
            pc += arr[i];
        }
        else{
            st++;
            if(st > n ||  arr[i] > l){
                return false;
            }
            pc = arr[i];
        }
    }
    return true;
}

int allocation(int *arr,int l,int r,int s,int n){
    if(l > r){
        return r+1;
    }
    int mid = l + (r - l) / 2;
    if(ispossible(arr,s,n,mid)){
        return allocation(arr,l,mid-1,s,n);
    }
    else{
        return allocation(arr,mid+1,r,s,n);
    }
}

int main(){
    int book[4] = {12,34,67,90};
    int size = 4;
    int num = 2;
    // cout<<sum(book,size);
    cout<<allocation(book,0,sum(book,size),size,num);
    return 0;
}