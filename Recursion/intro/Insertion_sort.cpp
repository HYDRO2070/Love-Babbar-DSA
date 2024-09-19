// insertion using recursion.

#include<bits/stdc++.h>
using namespace std;

void printarray(int arr[],int size){
    for(int i = 0;i < size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void Insertion_sort(int *arr,int i,int n){
    if(i == n){
        return;
    }
    int temp = arr[i];
    int j = i-1;
    for(j = i -1;j >= 0;j--){
        if(arr[j] > temp){
            arr[j+1] = arr[j];
        }
        else{
            break;
        }
    }
    arr[j+1] = temp;
    Insertion_sort(arr,i+1,n);

}


int main(){
    int arr[9] = {2,4,6,1,87,5,343,66,-1};
    printarray(arr,9);
    Insertion_sort(arr,1,9);
    printarray(arr,9);
    return 0;
}