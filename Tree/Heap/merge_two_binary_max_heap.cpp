#include<bits/stdc++.h>
using namespace std;

void print(vector<int> arr){
    for(int i = 0;i < arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void insert_heap(vector<int> &arr,int k,int num){
    arr[k] = num;
    while(k/2 > 0){
        cout<<"Hello"<<endl;
        if(arr[k] < arr[k/2]) return;
        else{
            swap(arr[k],arr[k/2]);
        }
        k /= 2;
    }
}

void solve(vector<int> &arr,int n,int i){
    // if(i < 1) return;
    int la = i;
    int left = 2*i;
    int right = 2*i+ 1;
    if(left < n && arr[la] < arr[left]){
        la = left;
    }
    if(right < n && arr[la] < arr[right]){
        la = right;
    }
    if(la != i){
        swap(arr[la],arr[i]);
        solve(arr,n,la);
    }
}


vector<int> solve(int *arr1,int *arr2,int n,int m){
    vector<int> ans(n+m+1,0);
    int k = 1;
    for(int i =0;i < n;i++){
        ans[k++] = arr1[i];
    }
    for(int i = 0;i < m;i++){
        // cout<<"koooon"<<endl;
        // insert_heap(ans,k,arr2[i]);
        ans[k++] = arr2[i];
    }
    int size = 8;
    for(int i = (size/2);i > 0;i--){
        solve(ans,size,i);
    }
    return ans;
}

int main(){
    int arr1[4] = {10,5,6,2};
    int arr2[3] = {12,7,9};
    print(solve(arr1,arr2,4,3));

    return 0;
}




        //         12
        //     10         9
        // 2       5   6      7