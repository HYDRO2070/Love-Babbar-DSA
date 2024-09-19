// it is an complete binary tree with the property of heap order.
// there are two type of heap property ehich are :
            // max heap - parent is the max element
            // min heap - parent is the min element
// it will start from 1 index
// where i s current node
// the left element can be found using (2*i) formula
// the right element can be found using (2*i +1) formula
// to find parent we will use (i/2)
// we wil impliment using array

#include<bits/stdc++.h>
using namespace std;


void solve(int *arr,int n,int i){
    // if(i < 1) return;
    int sa = i;
    int left = 2*i;
    int right = (2*i)+ 1;
    if(left <= n && arr[sa] > arr[left]){
        sa = left;
    }
    // cout<<arr[sa]<<" "<<arr[right]<<" "<<(right < n)<<endl;
    if(right <= n && arr[sa] > arr[right]){
        cout<<"hello"<<endl;
        sa = right;
    }
    if(sa != i){
        swap(arr[sa],arr[i]);
        solve(arr,n,sa);
    }
}

void heapify(int *arr,int size){

    for(int i = (size/2);i > 0;i--){
        solve(arr,size,i);
    }
    for(int i = 1;i <= size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}

int main(){


            //         54
            //     53      55
            // 52      50

    int arr[6] = {-1,54,53,55,52,50};
    int size = 5;
    heapify(arr,size);
    return 0;
}