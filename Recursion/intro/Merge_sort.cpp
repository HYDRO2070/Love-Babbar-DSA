// in this we r going to study merge sort using recursion.
// Inversion count

#include<bits/stdc++.h>
using namespace std;

void printarray(int arr[],int size){
    for(int i = 0;i < size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void merge(int *arr,int s,int m,int e){
    int i = s;
    int j = m+1;
    vector<int> ans;
    while(i <= m && j <= e){
        if(arr[i] < arr[j]){
            // arr[k] = arr[i];
            ans.push_back(arr[i]);
            i++;
        }
        else{
            ans.push_back(arr[j]);
            // arr[k] = arr[j];
            j++;
        }
    }
    while(i <= m){
            ans.push_back(arr[i]);
            i++;
    }
    while(j <= e){
            ans.push_back(arr[j]);
            j++;
        
    }
    for(i = 0;i < ans.size();i++){
        arr[s+i] = ans[i];
    }
}

void merge_sort(int *arr,int s,int e){
    // if(s >= e){
    //     return;
    // }
    if(s < e){
    // cout<<s<<" "<<e<<endl;
        int mid = s + (e - s) / 2;
        merge_sort(arr,s,mid);
        merge_sort(arr,mid+1,e);
        merge(arr,s,mid,e);
    }
}

int main(){
    int arr[9] = {2,4,6,1,87,5,343,66,-1};
    printarray(arr,9);
    merge_sort(arr,0,9-1);
    printarray(arr,9);
    return 0;
}