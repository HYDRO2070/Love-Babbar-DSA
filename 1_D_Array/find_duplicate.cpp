#include<iostream>
using namespace std;
int duplicate(int arr[],int size){
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans ^=arr[i];
        ans ^=i;
    }
    return ans;
    
}
int main(){
    int arr[] = {1,2,3,4,5,12,12};
    int size = sizeof(arr)/sizeof(int);
    cout<<duplicate(arr,size);
    return 0;
}