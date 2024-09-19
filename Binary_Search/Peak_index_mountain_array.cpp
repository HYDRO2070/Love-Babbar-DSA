#include<iostream>
using namespace std;
int peakindex(int arr[],int size){
    int left = 0;
    int right = size - 1;
    int mid = left + (right - left) /2;
    while(left < right){
        // if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]){
        //     return mid;
        // }
        if(arr[mid] < arr[mid+1]){
            left = mid + 1;

        }
        else{
            right = mid;
        }
        mid = left + (right - left) /2;
    }
    return left;
}
int main(){
    int arr[] = {3,4,5,6,7,1};
    int size = sizeof(arr) / sizeof(int);
    cout<<peakindex(arr,size);
    return 0;
}