// we have to use recursion to determine if a array is sorted or not.

#include<bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> arr,int i){
    if(i == arr.size()-1){
        return true;
    }
    return (arr[i] < arr[i+1]) && isSorted(arr,i+1);
}

bool antoher(int arr[],int size){
    if(size == 0)
    return true;
    if(arr[0] > arr[1])
    return false;
    else
    return antoher(arr+1,size-1);
}

int main(){
    // vector<int> arr;
    // arr.push_back(2);
    int arr[5] = {1,4,5,3,2};
    // arr.push_back(1);
    // arr.push_back(7);
    // arr.push_back(11);
    // arr.push_back(15);
    // arr.push_back(20);
    // cout<<isSorted(arr,0);
    cout<<antoher(arr,5);
    return 0;
}