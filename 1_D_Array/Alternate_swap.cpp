#include<iostream>
using namespace std;
void alterswap(int arr[],int size){
    for(int i = 0;i<(size);i = i + 2){
        arr[i] = arr[i]+arr[i+1];
        arr[i+1] = arr[i] - arr[i+1];
        arr[i] = arr[i] - arr[i+1];
    }
} 
int main(){
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(int);
    alterswap(arr,size);

    for(int i = 0;i<size;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}