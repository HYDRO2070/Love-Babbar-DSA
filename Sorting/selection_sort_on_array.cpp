#include<iostream>
using namespace std;
void printarray(int arr[],int size){
    for(int i = 0;i < size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int minpos(int arr[],int s,int e){
    int min = s;
    int i = -1;
    for(i = s + 1;i<=e;i++){
        if(arr[min] > arr[i]){
            min = i;
        }
    }
    return min;
}
void swap1(int arr[],int a,int b){
    arr[a] = arr[a] + arr[b];
    arr[b] = arr[a] - arr[b];
    arr[a] = arr[a] - arr[b];
}
void selection_sort(int arr[],int size){
    int pivot = 0;
    for(int i = 0;i<size-1;i++){
        int min = minpos(arr,i,size-1);
        if(i!=min){
        swap1(arr,i,min);
        }
    }
}
int main(){
    int arr[] = {2,4,6,1,87,5,343,66,-1};
    int size = sizeof(arr) / sizeof(int);
    printarray(arr,size);
    selection_sort(arr,size);
    printarray(arr,size);
    return 0;
}