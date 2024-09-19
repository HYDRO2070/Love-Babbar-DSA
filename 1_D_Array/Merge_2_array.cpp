#include<iostream>
#include<vector>
using namespace std;
void printans(vector<int> arr){
    for(int i = 0;i< arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
vector<int> merge(vector<int> arr1,vector<int> arr2){
    int i = 0,j =0;
    vector<int> ans;
    while(i < arr1.size() && j < arr2.size()){
        if(arr1[i]>arr2[j]){
            ans.push_back(arr2[j]);
            j++;
        }
        else{
            ans.push_back(arr1[i]);
            i++;
        }
    }
    while(i < arr1.size()){
        ans.push_back(arr1[i]);
            i++;
    }
    while(j < arr2.size()){
        ans.push_back(arr2[j]);
            j++;
    }
    return ans;
}
int main(){
    vector<int> arr1;
    vector<int> arr2;
    arr1.push_back(1);
    arr1.push_back(2);
    arr1.push_back(3);
    arr1.push_back(4);
    arr2.push_back(5);
    arr2.push_back(6);
    arr2.push_back(7);
    arr2.push_back(8);
    arr1 = merge(arr1,arr2);
    printans(arr1);
    return 0;
}