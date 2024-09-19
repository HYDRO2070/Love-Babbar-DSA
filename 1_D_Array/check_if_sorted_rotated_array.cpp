#include<iostream>
#include<vector>
#include<stdbool.h>
using namespace std;
void printans(vector<int> arr){
    for(int i = 0;i< arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
bool booli(vector<int> arr){
    int count = 0;
    int n = arr.size();
    for(int i =1;i<n;i++){
        if(arr[i-1] > arr[i]){
            count++;
        }
    }
    if(arr[n-1] > arr[0]){
        count++;
    }
    return count<=1;
}
int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(1);
    printans(arr);
    cout<<booli(arr);
    return 0;
}