// we have already study what is bubble sort. so in this we r going to implement bubble sort using recursion;


#include<bits/stdc++.h>
using namespace std;

void printarray(int arr[],int size){
    for(int i = 0;i < size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void swapping(int *arr,int i,int n){
    if(i+1 == n){
        return;
    }
    if(arr[i] > arr[i+1]){
        swap(arr[i],arr[i+1]);
    }
    swapping(arr,i+1,n);
}

void sort_bubble(int *arr,int n){
    if(n == 0 || n == 1){
        return;
    }

    // for(int i = 0;i < n-1;i++){
    //     if(arr[i] > arr[i+1]){
    //         swap(arr[i],arr[i+1]);
    //     }
    // }
    swapping(arr,0,n);
    sort_bubble(arr,n-1);
}

int main(){
    int arr[9] = {2,4,6,1,87,5,343,66,-1};
    printarray(arr,9);
    sort_bubble(arr,9);
    printarray(arr,9);
    return 0;
}