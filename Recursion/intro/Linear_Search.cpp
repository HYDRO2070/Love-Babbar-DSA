// use linear search using recursion

#include<bits/stdc++.h>
using namespace std;

bool linear(int arr[],int size,int t){
    cout<<"size"<<endl;
    if(size == 0){
        return false;
    }
    if(arr[0] == t){
        return true;
    }
    return linear(arr+1,size-1,t);
}

int main(){
    int arr[5] = {1,5,8,3,9};
    int size = 5;
    cout<<linear(arr,size,10);
    return 0;
}