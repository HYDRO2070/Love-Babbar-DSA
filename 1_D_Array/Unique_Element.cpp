#include<iostream>
using namespace std;
void PrintArray(int arr[],int size){
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<endl;
    }
}
int uniqueele(int arr[],int size){
    int ans = arr[0];
    for(int i = 1;i < size;i++){
        ans ^=arr[i];
    }
    return ans;
}
int main(){
    int arr[] = {1,2,3,3,4,2,1};
    int size= sizeof(arr)/sizeof(int);
    cout<<uniqueele(arr,size);
    return 0;
}