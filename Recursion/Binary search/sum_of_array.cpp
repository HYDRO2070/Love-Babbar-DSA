// return sum of array

#include<bits/stdc++.h>
using namespace std;

int sum(int arr[],int size){
    if(size == 0){
        return 0;
    }
    return arr[size - 1] + sum(arr,size-1);
}

int main(){
    int arr[5] = {1,3,5,2,8};
    int size = 5;
    cout<<sum(arr,size);
    return 0;
}