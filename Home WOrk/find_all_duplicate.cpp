#include<iostream>
#include<vector>
using namespace std;
void allduplicate(vector<int> arr){
    int bitmap = 0;
    for(int i = 0;i<arr.size();i++){
        int mask = 1 << arr[i];
        // cout<<mask<<endl;
        if(bitmap & mask){
        // cout<<(bitmap & mask)<<endl;
            cout<<arr[i]<<" ";
        }
        else{
            bitmap |= mask;
        // cout<<bitmap<<endl;
        }
    }
}
void removeduplicate(vector<int> arr){
    // int i = 0;
    // int j = i+1;
    // while(j < arr.size() && i < arr.size()){
    //     if(arr[j] == arr[i]){
    //         cout<<arr[j]<<" ";
    //         j++;
    //     }
    //     else{
    //         i = j;
    //         j = j + 1;
    //     }
    // }
    int bit = 0;
    for(int i =0;i<arr.size();i++){
        int mask = 1<<arr[i];
        if(bit&mask){
            cout<<arr[i]<<" ";
        }
        else{
            bit |= mask;
        }
    }
}
int main(){
    // int arr[] = {5,5,5,2};
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(5);
    // int size = sizeof(arr)/sizeof(int);
    // allduplicate(arr);
    removeduplicate(arr);
    return 0;
}