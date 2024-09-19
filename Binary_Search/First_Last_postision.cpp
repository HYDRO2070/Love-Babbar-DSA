#include<iostream>
using namespace std;
int FirstOccu(int arr[],int size,int target){
    int left = 0;
    int right = size -1;
    int mid = left + (right - left) / 2;
    int ans = -1;
    while(left <= right){
        if(arr[mid] == target){
            ans = mid;
            right = mid - 1;
        }
        else if(arr[mid] > target){
            right = mid -1;
        }
        else{
            left = mid +1;
        }
        mid = left + (right - left) / 2;
    }
    return ans;
}
int LastOccu(int arr[],int size,int target){
    int left = 0;
    int right = size -1;
    int mid = left + (right - left) / 2;
    int ans = -1;
    while(left <= right){
        if(arr[mid] == target){
            ans = mid;
            left = mid + 1;
        }
        else if(arr[mid] > target){
            right = mid -1;
        }
        else{
            left = mid +1;
        }
        mid = left + (right - left) / 2;
    }
    return ans;
}
int main(){
    int arr[] = {1,1,2,2,2,2,2,3,3,3,3,3,4,4,5,7};
    int size = sizeof(arr) / sizeof(int);
    int target = 7;
    cout<<FirstOccu(arr,size,target);
    cout<<LastOccu(arr,size,target);
    return 0;
}