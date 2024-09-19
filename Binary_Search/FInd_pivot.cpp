#include<iostream>
using namespace std;
int pivot(int arr[],int size){
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
    return left;
}
int main(){
    // int arr[] = {3,1};
    int arr[] = {1,1,1,1,1,2,1,1,1};
    int size = sizeof(arr) / sizeof(int);
    cout<<pivot(arr,size);
    return 0;
}