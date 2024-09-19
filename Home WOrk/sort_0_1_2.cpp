#include<iostream>
using namespace std;
void PrintArray(int arr[],int size){
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<",";
    }
}
void Swap(int arr[],int a,int b){
    arr[a] = arr[a] + arr[b];
    arr[b] = arr[a] - arr[b];
    arr[a] = arr[a] - arr[b];
}
void sort012(int arr[],int size){
    int left = 0,mid = 0,right = size-1;
    while(mid < right){
        if(arr[mid] == 0){
            Swap(arr,left,mid);
            left++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            Swap(arr,mid,right);
            right--;
        }
    }
}
int main(){
    int arr[] = {1,1,1,0,2,2,1,1,1,0,2,2,1,0};
    int size = sizeof(arr)/sizeof(int);
    sort012(arr,size);
    PrintArray(arr,size);
    return 0;
}