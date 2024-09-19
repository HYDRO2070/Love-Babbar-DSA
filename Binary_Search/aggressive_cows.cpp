#include<iostream>
using namespace std;
int maxi(int arr[],int size){
    int maxi = __WINT_MIN__;
    for(int i = 0;i<size;i++){
        if(maxi < arr[i]){
            maxi = arr[i];
        }
    }
    return maxi;
}
int mini(int arr[],int size){
    int maxi = __INT_MAX__;
    for(int i = 0;i<size;i++){
        if(maxi > arr[i]){
            maxi = arr[i];
        }
    }
    return maxi;
}
bool ispossible(int arr[],int size,int cows,int mid){
    int cowcount = 1;
    int last = arr[0];
    for(int i = 0;i<size;i++){
        if(arr[i] - last >= mid){
            cowcount++;
            if(cowcount == cows){
                return true;
            }
            last = arr[i];
        }
    }
    return false;
}
int position(int arr[],int size,int cows){
    int left = 0;
    int right = maxi(arr,size);
    int mid = left + (right - left) / 2;
    int ans = -1;
    while(left <= right){
        if(ispossible(arr,size,cows,mid)){
            ans = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
        mid = left + (right - left) / 2;
    }
    return ans;
}
int main(){
    int arr[] = {1,2,3};
    int cows = 2;
    int size = sizeof(arr) / sizeof(int);
    cout<<position(arr,size,cows);
    return 0;
}