// finding first and last place in the given array.

#include<bits/stdc++.h>
using namespace std;

int firstocc(int *arr,int l,int r,int t){
    // cout<<l<<" "<<r<<endl;
    // cout<<"he he he"<<endl;
    if(l > r){
        return -1;
    }
    int mid = l + (r - l) / 2;
    if(arr[mid] == t){
        int temp = firstocc(arr,l,mid-1,t);
        if(temp != -1){
            return min(temp,mid);
        }
        return mid;
    }
    else if(arr[mid] > t){
        return firstocc(arr,l,mid-1,t);
    }
    else{
        return firstocc(arr,mid + 1,r,t);
    }
}


int lastocc(int *arr,int l,int r,int t){
    if(l > r){
        return -1;
    }
    int mid = l + (r - l) / 2;
    if(arr[mid] == t){
        // cout<<mid<<endl;
        int temp = lastocc(arr,mid+1,r,t);
        if(temp != -1){
            return max(temp,mid);
        }
        return mid;
    }
    else if(arr[mid] > t){
        return lastocc(arr,l,mid-1,t);
    }
    else{
        return lastocc(arr,mid + 1,r,t);
    }
}

int main(){
    int arr[16] = {1,1,2,2,2,2,2,3,3,3,3,3,4,4,5,7};
    int size = 16;
    int t = 2;
    cout<<firstocc(arr,0,size-1,t)<<endl;
    cout<<lastocc(arr,0,size-1,t);
    return 0;
}