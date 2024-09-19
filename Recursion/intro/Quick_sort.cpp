// quick sort

#include<bits/stdc++.h>
using namespace std;

void printarray(int *arr,int s,int e){
    cout<<endl;
    for(int i = s;i <= e;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int part(int *arr,int s,int e){
    // printarray(arr,s,e);
    int i = s+1;
    int j = e;
    while(i <= j){
        // if(arr[j] < arr[i]){
        //     int temp = arr[i+1];
        //     arr[i+1] = arr[i];
        //     arr[i] = arr[j];
        //     arr[j] = temp;
        //     i++;
        // }
        // j--;
        if(arr[j] < arr[i-1]){
            swap(arr[i],arr[j]);
            swap(arr[i],arr[i-1]);
            i++;
        }
        else{

        j--;
        }

    }
    // printarray(arr,s,e);
    return i-1;
}

int partition(int *arr,int s,int e){
    // cout<<"HELLO"<<endl;
    int cnt = 0;
    for(int i = s+1;i <= e;i++){
        if(arr[i] < arr[s]){
            cnt++;
        }
    }
    int index = s+cnt;
    swap(arr[s],arr[index]);
    int i = s;
    int j = e;
    while(i < index && j > index){
        while(arr[i] < arr[index]){
            i++;
        }
        while(arr[j] > arr[index]){
            j--;
        }
        if(i < index && j > index){
            swap(arr[i++],arr[j--]);
        }
    }
    return index;
}

void QuickSort(int *arr,int s,int e){
    if(s < e){
        cout<<"HELLO"<<endl;
        int mid = part(arr,s,e);
        // int mid = partition(arr,s,e);
        QuickSort(arr,s,mid-1);
        QuickSort(arr,mid+1,e);
    }
}
int main(){
    int arr[9] = {2,4,6,1,87,5,343,66,-1};
    // int arr[9] = {9,8,7,6,5,4,3,2,1};
    printarray(arr,0,9-1);
    QuickSort(arr,0,9-1);
    // cout<<part(arr,0,8);
    printarray(arr,0,9-1);
    return 0;
}