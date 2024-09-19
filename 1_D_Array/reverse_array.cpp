#include<iostream>
using namespace std;
void reverse(int arr[],int size){
    for(int i = 0;i<(size/2);i = i + 1){
        arr[i] = arr[i]+arr[size-i-1];
        arr[size-i-1] = arr[i] - arr[size-i-1];
        arr[i] = arr[i] - arr[size-i-1];
    }
}

int main(){
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(int);
    reverse(arr,size);
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}