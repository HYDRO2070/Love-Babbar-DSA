// Best Case is O(n)
// Worst Case is O(n2)
#include<iostream>
using namespace std;
void printarray(int arr[],int size){
    for(int i = 0;i < size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void swap1(int arr[],int a,int b){
    arr[a] = arr[a] + arr[b];
    arr[b] = arr[a] - arr[b];
    arr[a] = arr[a] - arr[b];
}
void Bubble_sort(int arr[],int size){
    int booli = 0;
    for(int j = 0;j < size -1;j++){
        for(int i = 0;i < size -1 - j;i++){
            cout<<i<<endl;
        if(arr[i] > arr[i+1]){
            swap1(arr,i,i+1);
            booli = 1;
        }
    }
        if(booli == 0){
            break;
        }
    }
}
int main(){
    int arr[] = {2,4,6,1,87,5,343,66,-1};
    // int arr[] = {-1, 1 ,2, 4 ,5 ,6 ,66, 87 ,343};
    int size = sizeof(arr) / sizeof(int);
    printarray(arr,size);
    Bubble_sort(arr,size);
    printarray(arr,size);
    return 0;
}