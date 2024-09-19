#include<bits/stdc++.h>
using namespace std;

int solve(int *arr,int k,int size){
    priority_queue<int> pq;
    for(int i = 0;i < k;i++){
        pq.push(arr[i]);
    }
    for(int i = k;i < size;i++){
        if(arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}


int main(){
    int arr[6] = {7,10,4,3,20,15};
    int k = 3;
    cout<<solve(arr,k,6);
    return 0;
}