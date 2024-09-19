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
void Insertion_sort(int arr[],int size){
    for(int i = 1 ; i < size ; i++){
        int index = arr[i];
        int j = i - 1;
        for(j = i - 1 ; j >= 0 ; j--){
            if(arr[j] > index){
                arr[j + 1] = arr[j];
                // swap1(arr,j,index);
                // index--;
            }
            else{
                break;
            }
        }
        arr[j+1] = index;
    }
}
int main(){
    int arr[] = {2,4,6,1,87,5,343,66,-1};
    int size = sizeof(arr) / sizeof(int);
    printarray(arr,size);
    Insertion_sort(arr,size);
    printarray(arr,size);
    return 0;
}