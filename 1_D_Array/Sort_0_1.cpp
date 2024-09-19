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
    int i = 0;
    int j = size -1;
    while(i < j){
        while(arr[i] == 0 && i < j){
            i++;
        }
        while(arr[j] == 1 && i < j){
            j--;
        }
        if(i<j){
            Swap(arr,i,j);
        }
    }
}
int main(){
    int arr[] = {1,1,1,0,0,1,1,0,1,0};
    int size = sizeof(arr)/sizeof(int);
    sort012(arr,size);
    PrintArray(arr,size);
    return 0;
}