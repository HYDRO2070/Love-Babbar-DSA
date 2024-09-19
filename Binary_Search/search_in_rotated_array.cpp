#include<iostream>
using namespace std;
int Binary( int arr[],int begin,int end,int target){
    int left = begin;
    int right = end;
    int mid = left + (right - left) / 2;
    while(left <= right){
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] > target){
            right = mid -1;
        }
        else{
            left = mid +1;
        }
        mid = left + (right - left) / 2;
    }
    return -1;
}
int search(int arr[],int size,int target){
    int left = 0;
    int right = size - 1;
    int mid = left + (right - left) / 2;
    while(left < right){
        if(arr[mid] >= arr[0]){
            left = mid + 1;
        }
        else{
            right = mid;
        }
        mid = left + (right - left) / 2;
    }

    return (arr[left] <= target && arr[size-1] >= target) ? Binary(arr,left,(size-1),target) : Binary(arr,0,left-1,target);
}
int main(){
    int arr[] = {1,13};
    int target = 1;
    int size = sizeof(arr) / sizeof(int);
    cout<<search(arr,size,target);
    return 0;
}